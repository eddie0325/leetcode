/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        vector<string> ans;
        string current = "";
        backtrack(digits, 0, ans, current);
        return ans;
    }

    void backtrack(string& oriStr, int startIndex, vector<string>& ans, string& current) {
        if (startIndex == oriStr.length()) {
            ans.push_back(current);
            return;
        }

        char nowchar = oriStr[startIndex];
        auto nums = getDigit(nowchar);
        for (int i = 0; i < nums.size(); i++) {
            current += nums[i];
            backtrack(oriStr, startIndex + 1, ans, current);
            current.pop_back();
        }
    }

    string getDigit(char c) {
        return digitMap[c - '0'];
    }

    const vector<string> digitMap = {
        "",     "",     "abc",  "def", "ghi",  // 0~4
        "jkl",  "mno",  "pqrs", "tuv", "wxyz"  // 5~9
    };
};
// @lc code=end

