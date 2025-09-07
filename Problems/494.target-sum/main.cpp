/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // P - N = target
        // P + N = sum
        // P = (target + sum) / 2
        int sum = 0;
        for (int num: nums)
            sum += num;
        if ((sum + target) % 2 == 1 || abs(target) > sum)
            return 0;

        int positiveSum = (sum + target) / 2;
        // 問題變成：有多少種方式可以挑選子集，使得子集和為 P。
        vector<int> dp(positiveSum + 1, 0);
        dp[0] = 1;
        for (int num: nums) {
            for (int i = positiveSum; i >= num; i--) {
                dp[i] += dp[i - num];
            }
        }
        return dp[positiveSum];
    }
};
// @lc code=end

