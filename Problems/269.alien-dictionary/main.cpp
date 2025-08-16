// NeetCode

class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, int> indegree;
        unordered_map<char, unordered_set<char>> graph;
        // 初始化所有字母
        for (auto& word: words)
            for (auto& c: word)
                indegree[c] = 0;
        // 建 graph
        for (int i = 0; i < words.size() - 1; i++) {
            string& a = words[i];
            string& b = words[i+1];
            // 題目說如果有不合理的輸入就直接回傳
            if (a.size() > b.size() && a.substr(0, b.length()) == b)
                return "";

            pair<char, char> order;
            if (findOrder(a, b, order)) {
                if (graph[order.first].count(order.second) ==  0) {
                    graph[order.first].insert(order.second);
                    indegree[order.second]++;
                }
            } 
        }

        // indegree 0 推入queue
        queue<char> q;
        string ans = "";
        for (auto [c, count]: indegree)
            if (count == 0)
                q.push(c);
        // 將 indegree 0 的輸出答案
        while(!q.empty()) {
            char c = q.front();
            q.pop();
            ans += c;
            for (auto to: graph[c])
                if (--indegree[to] == 0)
                    q.push(to);
        }
        if (ans.length() != indegree.size()) return "";
        return ans;
    }

    bool findOrder(string& a, string& b, pair<char, char>& ans) {
        for (int i = 0; i < min(a.length(), b.length()); i++) {
            if (a[i] != b[i]) {
                ans = {a[i], b[i]};
                return true;
            }
        }
        return false;
    }
};
