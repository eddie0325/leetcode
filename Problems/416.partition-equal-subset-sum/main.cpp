/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
// #KEYPOINT 0-1 Knapsack
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto num: nums)
            sum += num;
        if (sum % 2 == 1) return false;
        int target = sum / 2;

        vector<bool> dp(target + 1, false);
        dp[0] = true;
        sort(nums.begin(), nums.end());
        // 每個num只能取一次，只有取或不取
        for (auto num: nums) {
            if (num > target) break;
            // 要從大到小更新，不然num會重複使用
            // 例如num=1 會一路把dp全都設為true
            for (int i = target - num; i >= 0; i--) {
                // 如果dp[i]可以組成，dp[i+num]也可以組成
                if (dp[i])
                    dp[i + num] = true;
            }
        }

        return dp[target];
    }
};
// @lc code=end

