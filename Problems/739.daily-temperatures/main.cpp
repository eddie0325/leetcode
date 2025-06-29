/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
// #KEYPOINT Monotonic Stack
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> needAnsDay; // 用來存還沒找到答案的「天數 index」
        
        for (int i = 0; i < temperatures.size(); i++) {
            while (!needAnsDay.empty() && temperatures[i] > temperatures[needAnsDay.top()]) {
                int needAnsDayIndex = needAnsDay.top();
                needAnsDay.pop();
                ans[needAnsDayIndex] = i - needAnsDayIndex;
            }
            needAnsDay.push(i);
        }
        return ans;
    }
};
// @lc code=end

