#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <dirent.h>
#include <sys/types.h>
#include <regex>

// #define DEBUG
using namespace std;

struct ProblemData {
    string name;
    int problemOrder;
    string problemTitle;
    string problemKey;
};

void traverseDirectory(const string& directoryPath, stringstream& readmeFile) {
    DIR* dir = opendir(directoryPath.c_str());
    if (!dir) {
        cerr << "Failed to open directory: " << directoryPath << "\n";
        return;
    }

    struct dirent* entry;
    vector<ProblemData> problemPaths;
    while ((entry = readdir(dir)) != nullptr) {
        string name = entry->d_name;
        if (name == "." || name == "..") continue;

        if (entry->d_type == DT_DIR) {
            // fetch problem information
            size_t end = name.find(".");
            int problemOrder = stoi(name.substr(0, end));
            string problemName = name.substr(end + 1);
            string problemKey = "";

            // check main.cpp exist
            ifstream readmeFile(directoryPath + name + "/main.cpp");
            if (!readmeFile.is_open()) {
                cerr << "Failed to open " << name << "/main.cpp for reading\n";
                continue;
            }

            string line;
            regex pattern("// #KEYWORD (.+)");
            smatch matches;

            while (getline(readmeFile, line)) {
                if (regex_search(line, matches, pattern)) {
                    if (matches.size() > 1) {
                        problemKey = matches[1].str();
                        break;
                    }
                }
            }
            problemPaths.push_back({name, problemOrder, problemName, problemKey}); 
        }
    }

    sort(problemPaths.begin(), problemPaths.end(), [](const ProblemData& a, const ProblemData& b) {
        return a.problemOrder < b.problemOrder;
    });

    readmeFile << "|Problem|Key|\n";
    readmeFile << "|-|-|\n";

    for (const ProblemData& problemData : problemPaths) {
        string name = problemData.name;
        int problemOrder = problemData.problemOrder;
        string problemTitle = problemData.problemTitle;
        string key = problemData.problemKey;
        readmeFile << "|[" << name << "](Problems/" << name << "/main.cpp)|" << key << "|\n";
    }
    closedir(dir);
}

int main() {
#ifdef DEBUG
    string readmeFilePath = "README.md";
    string problemPath = "Problems/";
#else
    string readmeFilePath = "../README.md";
    string problemPath = "../Problems/";
#endif

    fstream readmeFile(readmeFilePath);
    
    if (!readmeFile.is_open()) {
        cerr << "Failed to open README.md for reading\n";
        return 1;
    }

    stringstream buffer;
    buffer << readmeFile.rdbuf();
    readmeFile.close();
    string readmeContent = buffer.str();

    stringstream directoryStructure;

    traverseDirectory(problemPath, directoryStructure);

    string beginTag = "<!-- BEGIN DIRECTORY STRUCTURE -->";
    string endTag = "<!-- END DIRECTORY STRUCTURE -->";

    size_t beginPos = readmeContent.find(beginTag);
    size_t endPos = readmeContent.find(endTag);

    if (beginPos == string::npos || endPos == string::npos || beginPos >= endPos) { 
        cerr << "Failed to find the directory structure tags in README.md\n";
        return 1;
    }

    beginPos += beginTag.length();
    string newReadmeContent = readmeContent.substr(0, beginPos) + "\n" +
                                   directoryStructure.str() +
                                   readmeContent.substr(endPos);

    ofstream outFile(readmeFilePath);
    if (!outFile.is_open()) {
        cerr << "Failed to open README.md for writing\n";
        return 1;
    }

    outFile << newReadmeContent;
    outFile.close();

    return 0;
}