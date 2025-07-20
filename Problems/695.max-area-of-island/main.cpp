/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    dfs(grid, i, j, area);
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& grid, int x, int y, int& area) {
        grid[x][y] = 0;
        area++;

        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int xBound = grid.size();
        int yBound = grid[0].size();
        for (auto& d: dir) {
            int newX = x + d[0];
            int newY = y + d[1];
            if (newX >=0 && newX < xBound && newY >=0 && newY < yBound) {
                if (grid[newX][newY] == 1) {
                    dfs(grid, newX, newY, area);
                }
            }
        }
    }
};
// @lc code=end

