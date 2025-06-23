/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int area = 0;
        vector<int> leftMaxHeight(height.size(), 0);
        vector<int> rightMaxHeight(height.size(), 0);
        int nowMax = 0;
        for (int i = 1; i < height.size(); i++) {
            nowMax = max(nowMax, height[i - 1]);
            leftMaxHeight[i] = nowMax;
        }
        nowMax = 0;
        for (int i = height.size() - 2; i >= 0; i--) {
            nowMax = max(nowMax, height[i + 1]);
            rightMaxHeight[i] = nowMax;
        }
        for (int i = 0; i < height.size(); i++) {
            int minEdge = min(leftMaxHeight[i], rightMaxHeight[i]);
            if (height[i] < minEdge)
                area += minEdge - height[i];
        }
        return area;
    }
};
// @lc code=end

