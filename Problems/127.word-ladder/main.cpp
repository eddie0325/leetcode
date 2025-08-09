/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 找beginWord到endWord的最短距離 BFS
        unordered_map<string, vector<string>> patternMap;
        unordered_map<string, int>  wordToIndex;

        // 確認 endWord 是否存在 wordList
        bool foundEnd = false;
        for (const auto& w : wordList) {
            if (w == endWord) foundEnd = true;
        }
        if (!foundEnd) return 0;

        // 若 beginWord 不在 wordList，加入
        bool foundBegin = false;
        for (const auto& w : wordList) {
            if (w == beginWord) foundBegin = true;
        }
        if (!foundBegin) wordList.push_back(beginWord);

        vector<vector<int>> graph(wordList.size());
        vector<bool> visited(wordList.size(), false);

        // 單字建立 pattern map 
        // cat 放到 *at c*t ca* 
        for (int i = 0; i < wordList.size(); i++) {
            string& word = wordList[i];
            for (int j = 0; j < word.size(); j++) {
                string pattern = word;
                pattern[j] = '*';
                patternMap[pattern].push_back(word);
            }
            wordToIndex[word] = i;
        }
        // 建立 graph
        for (int i = 0; i < wordList.size(); i++) {
            string& word = wordList[i];
            for (int j = 0; j < word.size(); j++) {
                string pattern = word;
                pattern[j] = '*';
                for (auto neighbor: patternMap[pattern]) {
                    if (wordToIndex[neighbor] != i)
                        graph[i].push_back(wordToIndex[neighbor]);
                } 
            }
        }
        // 從 beginWord 開始
        queue<int> q;
        q.push(wordToIndex[beginWord]);
        visited[wordToIndex[beginWord]] = true;
        int level = 1;
        while(!q.empty()) {
            // 只處理這一層
            int levelCount = q.size();
            while(levelCount--) {
                int index = q.front();
                q.pop();
                if (wordList[index] == endWord) return level;
                for(auto nextLevel: graph[index]) {
                    if (!visited[nextLevel]) {
                        q.push(nextLevel);
                        visited[nextLevel] = true;
                    } 
                }
            }
            level++;
        }
        return 0;
    }
};
// @lc code=end

