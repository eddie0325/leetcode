/*
 * @lc app=leetcode id=3174 lang=cpp
 *
 * [3174] Clear Digits
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                ans.pop_back();
            }
            else {
                ans += s[i];
            }
        }
        return ans;
    }
};
// @lc code=end

