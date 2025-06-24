/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int lowest = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            maxProfit = max(maxProfit, prices[i] - lowest);
            lowest = min(lowest, prices[i]);
        }
        return maxProfit;
    }
};

// @lc code=end

