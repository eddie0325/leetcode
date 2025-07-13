/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // 題目要求找出距離前k個點
        // 答案有可能不唯一，題目都可以接受= =
        // maxHeap
        using P = pair<int, vector<int>>;
        auto cmp = [](const P &a, const P &b) {
            return a.first < b.first;
        };
        priority_queue<P, vector<P>, decltype(cmp)> maxHeap(cmp);

        for (int i = 0; i < points.size(); i++) {
            auto point = points[i];
            int x = point[0];
            int y = point[1];
            int distance = (x * x + y * y);
            maxHeap.push({distance, point});
            if (maxHeap.size() > k)
                maxHeap.pop();
        }

        vector<vector<int>> ans;
        while(!maxHeap.empty()) {
            auto point = maxHeap.top().second;
            ans.push_back(point);
            maxHeap.pop();
        }
        
        return ans;
    }
};
// @lc code=end

