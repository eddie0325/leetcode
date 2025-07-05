/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
// #KEYPOINT Tortoise and Hare Algorithm
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Detect cycle using Floyd's Tortoise and Hare algorithm
        // 1.偵測環
        int slow = nums[0];
        int fast = nums[0];
        while(true) {
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
            if (slow == fast)
                break;
        }
        // 2.找環的起點，也就是重複的數字
        slow = nums[0];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
// @lc code=end

