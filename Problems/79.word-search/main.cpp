/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int w = board[0].size();
        int h = board.size();
        vector<vector<bool>> used(h, vector<bool>(w, false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    if(dfs(board, word, 0, i, j, used))
                        return true;
                }
            }
        }
        return false;
    }

    bool dfs(const vector<vector<char>>& board, const string word, int targetIndex, int row, int col, vector<vector<bool>>& used) {
        int w = board[0].size();
        int h = board.size();
        if (row >= h || row < 0 || col >= w || col < 0)
            return false;
        if (word[targetIndex] != board[row][col] || used[row][col])
            return false;
        // 找完了
        if (targetIndex == word.size() - 1) return true;
        // 找下一個
        used[row][col] = true;
        bool hasFind = 
            dfs(board, word, targetIndex + 1, row, col - 1, used) ||
            dfs(board, word, targetIndex + 1, row, col + 1, used) ||
            dfs(board, word, targetIndex + 1, row - 1, col, used) ||
            dfs(board, word, targetIndex + 1, row + 1, col, used);
        used[row][col] = false;
        return hasFind;
    }
};
// @lc code=end

