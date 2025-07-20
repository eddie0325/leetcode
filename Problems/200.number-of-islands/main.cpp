/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>>& grid, int x, int y) {
        grid[x][y] = '0';
        int xBound = grid.size();
        int yBound = grid[0].size();
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto &d: dir) {
            int newX = x + d[0];
            int newY = y + d[1];
            if (newX >=0 && newX < xBound && newY >=0 && newY < yBound) {
                char c = grid[newX][newY];
                if (c == '1')
                    dfs(grid, newX, newY);
            }
        }
    }
};
// @lc code=end

