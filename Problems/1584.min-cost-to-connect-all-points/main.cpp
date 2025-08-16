/*
 * @lc app=leetcode id=1584 lang=cpp
 *
 * [1584] Min Cost to Connect All Points
 */

// @lc code=start
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        auto cmp = [](pair<int, int>& a, pair<int, int>& b){
            return a.first > b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);
        vector<bool> visited(points.size(), false);
        
        int ans = 0, visitedCount = 0;
        minHeap.push({0, 0});
        while(visitedCount < points.size()) {
            auto [cost, index] = minHeap.top();
            minHeap.pop();
            if (visited[index])
                continue;
            // 拿最近一個點加入 MST
            ans+= cost;
            visitedCount++;
            visited[index] = true;
            // 更新剩下的點的cost
            for (int i = 0; i < points.size(); i++) {
                if (visited[i])
                    continue;
                int distX = abs(points[index][0] - points[i][0]);
                int distY = abs(points[index][1] - points[i][1]);
                minHeap.push({distX + distY, i});
            }
        }
        return ans;
    }
};
// @lc code=end

