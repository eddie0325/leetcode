/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int w = board[0].size();
        int h = board.size();
        vector<vector<bool>> visited(h, vector<bool>(w, false));
        // 將周圍的O加到queue
        queue<pair<int, int>> freeQueue;
        for (int i = 0; i < w; i++) {
            if (board[0][i] == 'O') {
                freeQueue.push({0, i});
                visited[0][i] = true;
            }
            if (board[h - 1][i] == 'O') {
                freeQueue.push({h - 1, i});
                visited[h - 1][i] = true;
            }
        }
        for (int i = 0; i < h; i++) {
            if (board[i][0] == 'O') {
                freeQueue.push({i, 0});
                visited[i][0] = true;
            }
            if (board[i][w - 1] == 'O') {
                freeQueue.push({i, w - 1});
                visited[i][w - 1] = true;
            }
        }
        bfs(freeQueue, visited, board);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (board[i][j] == 'O' && !visited[i][j])
                    board[i][j] = 'X';
            }
        }
    }

    void bfs(queue<pair<int, int>> &q, vector<vector<bool>>& visited, vector<vector<char>>& board) {
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            for (auto& d: dir) {
                int newRow = row + d[0];
                int newCol = col + d[1];
                if (!checkBound(newRow, newCol, board))
                    continue;
                if (visited[newRow][newCol])
                    continue;
                if (board[newRow][newCol] == 'O') {
                    q.push({newRow, newCol});
                    visited[newRow][newCol] = true;
                }
            }
        }
    }

    bool checkBound(int row, int col, vector<vector<char>>& board) {
        int w = board[0].size();
        int h = board.size();
        return row >= 0
            && row < h
            && col >= 0
            && col < w;
    }
};
// @lc code=end

