/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
#include <algorithm>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        /*
        // 等同於前n-k個丟到後面去
        int res = nums.size() - k;
        nums.insert(nums.end(), nums.begin(), nums.begin() + res);
        nums.erase(nums.begin(), nums.begin() + res);
        */
        
        // 1 2 3 4 5 6 7
        // -> 7 6 5 4 3 2 1
        // 7 6 5 | 4 3 2 1
        // 各自reverse
        // 5 6 7 1 2 3 4
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
// @lc code=end

