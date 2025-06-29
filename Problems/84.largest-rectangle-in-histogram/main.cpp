/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
// #KEYPOINT Monotonic Stack
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 長方形的高取決於最矮的柱子
        // 從每根柱子出發，假設自己是最矮的，找出左右邊界(比自己還矮就是左右邊界)作為長方形的長
        // 單調遞增堆疊，來快速找出：每個柱子左邊、右邊第一個比它矮的柱子
        int maxArea = 0;
        stack<int> indexStack;
        heights.insert(heights.begin(), 0); // 在前後各加一根高度為 0 的柱子，幫助邊界處理
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++) {
            // 若目前柱子高度 < 堆疊頂部對應的柱子高度，表示目前柱子是堆疊頂部那根柱子的右邊界
            while(!indexStack.empty() && heights[indexStack.top()] > heights[i]) {
                int height = heights[indexStack.top()];
                indexStack.pop();
                int length = i - indexStack.top() - 1; // 左邊界是新的堆疊頂部
                int area = height * length;
                maxArea = max(maxArea, area);
            }
            indexStack.push(i);
        }
        return maxArea;
    }
};
// @lc code=end

