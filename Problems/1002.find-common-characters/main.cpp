/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 */

// @lc code=start
// #define DEBUG
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int commonCount[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int nowCount[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        vector<string> ans;
        for (int i = 0; i < words.size(); ++i) {
            for (auto c : words[i]) {
                nowCount[c - 'a']++;
            }

            for (int j = 0; j < 26; ++j) {
                if (i == 0) {
                    commonCount[j] = nowCount[j];
                }
                else {
                    commonCount[j] = min(commonCount[j], nowCount[j]);
                }
                nowCount[j] = 0;
            }
        }
        
        for (int i = 0; i < 26; ++i) {
            while(commonCount[i]--) {
                ans.push_back(string(1, 'a' + i));
            }
        }
        return ans;
    }
};
#ifdef DEBUG
int main() {
    Solution s;
    vector<string> words = {"cool","lock","cook"};
    auto ans = s.commonChars(words);
    return 0;
}
#endif
// @lc code=end

