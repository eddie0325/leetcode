/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans;
        // dp_max[i] = 以 nums[i] 結尾的最大乘積
        // dp_min[i] = 以 nums[i] 結尾的最小乘積
        vector<int> dp_max(n, 1);
        vector<int> dp_min(n, 1);

        dp_max[0] = dp_min[0] = ans = nums[0];

        for (int i = 1; i < n; i++) {
            int cand1 = nums[i];
            int cand2 = dp_max[i - 1] * nums[i];
            int cand3 = dp_min[i - 1] * nums[i];
            dp_max[i] = max({cand1, cand2, cand3});
            dp_min[i] = min({cand1, cand2, cand3});
            ans = max(ans, dp_max[i]);
        }

        return ans;
    }
};
// @lc code=end

