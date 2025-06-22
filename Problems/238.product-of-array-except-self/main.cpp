/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // // ans = left product * right product
        // vector<int> leftProduct(nums.size(), 1);
        // vector<int> rightProduct(nums.size(), 1);
        // vector<int> ans(nums.size());
        // int now = 1;
        // for (int i = 1; i < nums.size(); i++) {
        //     now *= nums[i - 1];
        //     leftProduct[i] = now;
        // }
        // now = 1;
        // for (int i = nums.size() - 2; i >= 0; i--)
        // {
        //     now *= nums[i + 1];
        //     rightProduct[i] = now;
        // }
        // for (int i = 0; i < nums.size(); i++) {
        //     ans[i] = leftProduct[i] * rightProduct[i];
        // }
        // return ans;

        // ans = left product * right product
        vector<int> ans(nums.size(), 1);
        // use ans for leftProduct
        int prefix = 1;
        for (int i = 1; i < nums.size(); i++) {
            prefix *= nums[i - 1];
            ans[i] = prefix;
        }
        prefix = 1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            prefix *= nums[i + 1];
            ans[i] *=prefix;
        }
        return ans;
    }
};
// @lc code=end

