/*
 * @lc app=leetcode id=3110 lang=cpp
 *
 * [3110] Score of a String
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;
        for (int i = 0; i < s.length() - 1; ++i) {
            sum += abs(s[i] - s[i + 1]);
        }
        return sum;
    }
};
// @lc code=end

