/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> check;
        unordered_map<char, char>matchMap = {
            { ')', '(' },
            { '}', '{' },
            { ']', '[' }
        };
        for (int i = 0; i < s.length(); i++) {
            if (matchMap.count(s[i])) {
                if (check.empty() || check.top() != matchMap[s[i]])
                    return false;
                check.pop();
            }
            else {
                check.push(s[i]);
            }
        }
        return check.empty();
    }
};
// @lc code=end

