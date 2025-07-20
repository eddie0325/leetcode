/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> usedCol(n, false);
        // 同一對角線 row - col 是固定值
        // 值域 -(n-1) ~ (n-1)
        vector<bool> usedDiag1(2 * n - 1, false);
        // 同一反對角線 row + col 是固定值
        // 值域 0 ~ 2n-2
        vector<bool> usedDiag2(2 * n - 1, false);
        vector<vector<string>> ans;
        vector<string> current;
        backtrack(n, ans, usedCol, usedDiag1, usedDiag2, current, 0);
        return ans;
    }

    void backtrack(int n, vector<vector<string>> &ans, vector<bool> &usedCol, vector<bool> &usedDiag1, vector<bool> &usedDiag2, vector<string> &current, int row){
        if (row == n) {
            ans.push_back(current);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (canPlace(row, col, n, usedCol, usedDiag1, usedDiag2)) {
                string cur(n, '.');
                cur[col] = 'Q';
                current.push_back(cur);
                // set state
                usedCol[col] = true;
                usedDiag1[row - col + n - 1] = true;
                usedDiag2[row + col] = true;

                backtrack(n, ans, usedCol, usedDiag1, usedDiag2, current, row + 1);
                
                // backtrack
                current.pop_back();
                usedCol[col] = false;
                usedDiag1[row - col + n - 1] = false;
                usedDiag2[row + col] = false;
            }
        }
    }

    bool canPlace(int row, int col, int n, vector<bool> &usedCol, vector<bool> &usedDiag1, vector<bool> &usedDiag2) {
        bool check1 = usedCol[col];
        bool check2 = usedDiag1[row - col + n - 1];
        bool check3 = usedDiag2[row + col];
        return !(check1 || check2 || check3);
    }
};
// @lc code=end

