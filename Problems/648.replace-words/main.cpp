/*
 * @lc app=leetcode id=648 lang=cpp
 *
 * [648] Replace Words
 */

// @lc code=start
// #define DEBUG
#include <vector>
#include <string>
using namespace std;

// Trie(prefix tree)
class Trie {
public:
    Trie* children[26];
    bool isEnd;
    Trie() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        isEnd = false;
    }
};

class Solution {
public:

    Trie* root = new Trie();
    
    void insertTrie(string& word) {
        Trie* cur = root;
        for (auto& c : word) {
            if (cur->children[c - 'a'] == nullptr) {
                cur->children[c - 'a'] = new Trie();
            }
            cur = cur->children[c - 'a'];
        }
        cur->isEnd = true;
    }

    string replaceWord(string& word) {
        string answer = "";
        Trie* cur = root;
        for (auto& c : word) {
            if (cur->children[c - 'a'] == nullptr) {
                return word;
            }
            answer += c;
            cur = cur->children[c - 'a'];

            // 只有完整走到end才回傳answer
            // 不用考慮cat和catt的情況，在cat就會End了
            if (cur->isEnd) {
                return answer;
            }
        }
        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        // 題目意思應該是prefix，而不是包含

        // 建立trie(prefix tree)
        for (auto& d : dictionary) {
            insertTrie(d);
        }
        
        // 切string
        char delimiter = ' ';
        string::size_type start = 0;
        string::size_type end = sentence.find(delimiter);
        string word;
        string answer = "";
        while (end != string::npos) {
            word = sentence.substr(start, end - start);
            start = end + 1;
            end = sentence.find(delimiter, start);
            answer += replaceWord(word);
            answer += delimiter;
        }
        word = sentence.substr(start);
        answer += replaceWord(word);

        return answer;
    }
};
#ifdef DEBUG
int main() {
    Solution s;
    vector<string> dict = {"cat","bat","catt","rat"};
    string sentence = "the cattle was rattled by the battery";
    string ans = s.replaceWords(dict, sentence);
    return 0;
}
#endif
// @lc code=end

