/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 從終點開始找，如果此點是可以到達終點，此點就做為新的終點
        int target = nums.size() - 1;
        while (target > 0) {
            bool flag = false;
            for (int i = target - 1; i >= 0; i--) {
                if (nums[i] >= target - i) {
                    target = i;
                    flag = true;
                    break;
                }
            }
            if (flag == false) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

