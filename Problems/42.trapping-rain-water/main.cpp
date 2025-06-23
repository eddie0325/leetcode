/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        // prefix sum + suffix sum
        // int area = 0;
        // vector<int> leftMaxHeight(height.size(), 0);
        // vector<int> rightMaxHeight(height.size(), 0);
        // int nowMax = 0;
        // for (int i = 1; i < height.size(); i++) {
        //     nowMax = max(nowMax, height[i - 1]);
        //     leftMaxHeight[i] = nowMax;
        // }
        // nowMax = 0;
        // for (int i = height.size() - 2; i >= 0; i--) {
        //     nowMax = max(nowMax, height[i + 1]);
        //     rightMaxHeight[i] = nowMax;
        // }
        // for (int i = 0; i < height.size(); i++) {
        //     int minEdge = min(leftMaxHeight[i], rightMaxHeight[i]);
        //     if (height[i] < minEdge)
        //         area += minEdge - height[i];
        // }
        // return area;

        // two pointer
        int area = 0;
        int left = 0;
        int right = height.size() - 1;
        int leftMax = height[left];
        int rightMax = height[right];
        while(left < right) {
            if (leftMax < rightMax) {
                left++;
                leftMax = max(leftMax, height[left]);
                area += leftMax - height[left];
            }
            else {
                right--;
                rightMax = max(rightMax, height[right]);
                area += rightMax - height[right];
            }
        }
        return area;
    }
};
// @lc code=end

