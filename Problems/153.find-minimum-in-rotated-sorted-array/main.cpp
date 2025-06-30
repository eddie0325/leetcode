/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) // 最小值在右半邊，並不可能是mid
                left = mid + 1;
            else { // 最小值在左半邊，有可能是mid
                right = mid;
            }
        }
        return nums[left];
    }
};
// @lc code=end

