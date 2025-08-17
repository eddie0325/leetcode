/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

// @lc code=start
// #KEYPOINT Bellman-Ford
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // // 每次抓最小cost的出來
        // auto cmp = [](pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b) {
        //     return a.first > b.first;
        // };
        // priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(cmp)> minHeap(cmp);
        
        // vector<vector<pair<int, int>>> graph(n);
        // for (auto& flight: flights) {
        //     graph[flight[0]].push_back({flight[1], flight[2]});
        // }
        
        // minHeap.push({0, {src, 0}});
        // while(!minHeap.empty()) {
        //     auto [cost, data] = minHeap.top();
        //     minHeap.pop();
        //     int airport = data.first;
        //     int step = data.second;
        //     if (airport == dst) {
        //         return cost;
        //     }
        //     if (step == k + 1) continue;
        //     // 這個機場能前往的機場
        //     for (auto [next, price]: graph[airport]) {
        //         minHeap.push({cost + price, {next, step + 1}});
        //     }
        // }
        // return -1;



        // vector<int, vector<pair<int, int>>> graph(n);
        // for (auto& flight: flights) {
        //     graph[flight[0]].push_back({flight[1], flight[2]});
        // }
        // src 到各點的 minCost
        vector<int> minCost(n, INT_MAX);
        minCost[src] = 0;

        // k 是中繼站數量，要跑 k+1 輪
        for (int i = 0; i <= k; i++) {
            // 避免同一輪互相影響，這輪更新只用上輪結果
            vector<int> temp = minCost;
            for (auto flight: flights) {
                int from = flight[0];
                int to = flight[1];
                int price = flight[2];
                if (minCost[from] != INT_MAX)
                    temp[to] = min(temp[to], minCost[from] + price);
            }
            minCost = temp;
        }
        if (minCost[dst] == INT_MAX) return -1;
        return minCost[dst];
    }
};
// @lc code=end

