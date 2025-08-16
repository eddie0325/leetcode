/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start
// #KEYPOINT Hierholzer’s Algorithm
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 找 Euler Tour
        // multiset自動維持字典順序
        unordered_map<string, multiset<string>> graph;
        for (auto& ticket: tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }
        vector<string> ans;
        dfs("JFK", graph, ans);
        // Hierholzer’s 結果是逆序的
        reverse(ans.begin(), ans.end());
        return ans;
    }

    void dfs(string airport, unordered_map<string, multiset<string>>& graph, vector<string>& ans) {
        auto& dest = graph[airport];
        // 對這個airport來說，每條邊都要走過
        while(!dest.empty()) {
            string next = *dest.begin(); // 取最小字典序的票
            dest.erase(dest.begin()); // 這個邊用掉了
            dfs(next, graph, ans);
        }
        // 邊全都走過了
        ans.push_back(airport);
    }
};
// @lc code=end

