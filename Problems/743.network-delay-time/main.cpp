/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */

// @lc code=start
// #KEYPOINT Dijkstra
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        auto cmp = [](pair<int, int> a, pair<int, int> b) {
            return a.first > b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeapQueue(cmp);
        vector<vector<pair<int, int>>> graph(n + 1); // graph[u]有各pair<v, w>
        vector<int> distance(n + 1, INT_MAX);

        for (auto time: times) {
            int u = time[0];
            int v = time[1];
            int w = time[2];
            graph[u].push_back({v, w});
        }
        // 從 k 開始
        distance[k] = 0;
        minHeapQueue.push({0, k});
        while(!minHeapQueue.empty()) {
            auto [curDist, node] = minHeapQueue.top();
            minHeapQueue.pop();
            if (curDist > distance[node]) continue;

            for (auto time: graph[node]) {
                int neighbor = time.first;
                int delay = time.second;
                int newDist = curDist + delay;
                if (distance[neighbor] > newDist) {
                    distance[neighbor] = newDist;
                    minHeapQueue.push({newDist, neighbor});
                }
            }
        }
        
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (distance[i] == INT_MAX) return -1;
            maxTime = max(distance[i], maxTime);
        }
        return maxTime;
    }
};
// @lc code=end

