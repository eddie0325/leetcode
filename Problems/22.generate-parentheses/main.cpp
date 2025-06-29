/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
// #KEYPOINT backtracking
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtracking(0, 0, "", ans, n);
        return ans;
    }

    void backtracking(int leftUsed, int rightUsed, string nowString, vector<string> &ans, int n) {
        if (n == leftUsed && n == rightUsed) {
            ans.push_back(nowString);
            return;
        }
        if (leftUsed < n) {
            backtracking(leftUsed + 1, rightUsed, nowString + "(", ans, n);
        }
        if (rightUsed < leftUsed) {
            backtracking(leftUsed, rightUsed + 1, nowString + ")", ans, n);
        }
    }
};
// @lc code=end

