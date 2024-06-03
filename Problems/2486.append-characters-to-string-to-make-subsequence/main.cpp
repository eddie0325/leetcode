/*
 * @lc app=leetcode id=2486 lang=cpp
 *
 * [2486] Append Characters to String to Make Subsequence
 */

// @lc code=start
// #define DEBUG
#include <string>
using namespace std;
class Solution {
public:
    int appendCharacters(string s, string t) {
        int t_length = t.length();
        int s_length = s.length();
        int nowIndex = 0;
        int nowPointer = 0;
        while(nowIndex < t_length && nowPointer < s_length) {
            char target = t[nowIndex];
            if (s[nowPointer] == target) {
                nowIndex++;
                nowPointer++;
            } else {
                nowPointer++;
            }
        }
        return t_length - nowIndex;
    }
};
#ifdef DEBUG
int main() {
    Solution s;
    int ans = s.appendCharacters("coaching", "coding");
    return 0;
}
#endif
// @lc code=end

