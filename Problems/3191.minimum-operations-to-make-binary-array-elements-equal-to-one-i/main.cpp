/*
 * @lc app=leetcode id=3191 lang=cpp
 *
 * [3191] Minimum Operations to Make Binary Array Elements Equal to One I
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] == 0) {
                ++count;
                nums[i + 1] = nums[i + 1] == 0 ? 1 : 0;
                nums[i + 2] = nums[i + 2] == 0 ? 1 : 0;
            }
        }
        if (nums[nums.size() - 2] == 0 || nums[nums.size() - 1] == 0) {
            return -1;
        }
        return count;
    }
};
// @lc code=end

