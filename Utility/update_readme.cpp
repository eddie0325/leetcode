#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <dirent.h>
#include <sys/types.h>

using namespace std;

struct ProblemData {
    string name;
    int problemOrder;
    string problemTitle;
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
            size_t end = name.find(".");
            int problemOrder = stoi(name.substr(0, end));
            string problemName = name.substr(end + 1);
            problemPaths.push_back({name, problemOrder, problemName}); 
        }
    }

    sort(problemPaths.begin(), problemPaths.end(), [](const ProblemData& a, const ProblemData& b) {
        return a.problemOrder < b.problemOrder;
    });

    readmeFile << "|Problem|Key|\n";
    readmeFile << "|-|-|\n";

    for (const ProblemData& problemPath : problemPaths) {
        string name = problemPath.name;
        int problemOrder = problemPath.problemOrder;
        string problemTitle = problemPath.problemTitle;
        string key = " "; // TODO: Add key
        readmeFile << "|[" << name << "](Problems/" << name << "/main.cpp)|" << key << "|\n";
    }
    closedir(dir);
}

int main() {
    ifstream readmeFile("README.md");
    if (!readmeFile.is_open()) {
        cerr << "Failed to open README.md for reading\n";
        return 1;
    }

    stringstream buffer;
    buffer << readmeFile.rdbuf();
    readmeFile.close();
    string readmeContent = buffer.str();

    stringstream directoryStructure;
    traverseDirectory("Problems/", directoryStructure);  // 从当前目录开始遍历

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

    ofstream outFile("../README.md");
    if (!outFile.is_open()) {
        cerr << "Failed to open README.md for writing\n";
        return 1;
    }

    outFile << newReadmeContent;
    outFile.close();

    return 0;
}