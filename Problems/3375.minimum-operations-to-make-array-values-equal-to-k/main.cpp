/*
 * @lc app=leetcode id=3375 lang=cpp
 *
 * [3375] Minimum Operations to Make Array Values Equal to K
 */

// @lc code=start
#include <algorithm>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int result = 0;
        int last = k;

        if (nums[0] < k) {
            return -1;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != last) {
                result++;
            }
            last = nums[i];
        }
        return result;
    }
};
// @lc code=end

