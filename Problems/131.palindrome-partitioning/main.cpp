/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
// #KEYPOINT backtracking
// #define DEBUG
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<string>> partition(string s) {
        return findPartition(s);
    }

    vector<vector<string>> findPartition(string s) {
        // if (s.empty()) {
        //     return {};
        // }
        // else if (s.size() == 1) {
        //     return {{s}};
        // }
        // vector<vector<string>> res;

        // // 從第一個字符開始的substr開始往後找
        // for (int i = 1;i < s.size();++i) {
        //     string substr = s.substr(0, i);
        //     if (isPalindrome(substr)) {
        //         vector<vector<string>> afterPartition = findPartition(s.substr(i));
        //         for (vector<string> &v:afterPartition) {
        //             v.insert(v.begin(), substr);
        //         }
        //         res.insert(res.end(), afterPartition.begin(), afterPartition.end());
        //     }
        // }

        // if (isPalindrome(s)) {
        //     res.push_back({s});
        // }


        int n = s.size();

        // 建立回文表
        // dp[i][j]表示是否回文
        vector<vector<bool>>dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        // space表示ij間距(space1長度為2)
        for (int space = 1; space < n; ++space) { // 依續找不同長度的回文
            for(int i = 0; i < n - space; ++i) {
                int j = i + space;
                if (s[i] == s[j] && (space == 1 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                }
            }
        }

        vector<string> path;
        vector<vector<string>> res;
        backtrack(s, 0, path, res, dp);
                
        return res;
    }

    void backtrack(const string &s, int start, vector<string> &path, vector<vector<string>> &res, vector<vector<bool>> &dp) {
        if (start == s.size()) {
            // 這組跑完了，把經過的路徑加入結果
            res.push_back(path);
            return;
        }
        for(int end = start; end < s.size(); ++end) {
            if (dp[start][end]) {
                path.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, path, res, dp);
                path.pop_back(); // 回溯
            }
        }
    }
};

#ifdef DEBUG
int main() {
    Solution s;
    auto res = s.partition("aa");
    return 0;
}
#endif
// @lc code=end

