/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = 10001;
        int maxPrice = -1;
        int profit = 0;
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
                maxPrice = -1;
            }
            maxPrice = max(maxPrice, prices[i]);
            profit = max(profit, maxPrice - minPrice);
        }
        return profit;
    }
};

// @lc code=end

