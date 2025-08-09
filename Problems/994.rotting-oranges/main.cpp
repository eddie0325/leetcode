/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int freshCount = 0;
        queue<pair<int, int>> rottenQueue;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    freshCount++;
                else if (grid[i][j] == 2) {
                    rottenQueue.push({i, j});
                }
            }
        }
        
        // bfs
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int ansTime = 0;
        while (!rottenQueue.empty()) {
            // 這層有幾個
            int levelSize = rottenQueue.size();
            bool infected = false;
            while(levelSize--) {
                auto [row, col] = rottenQueue.front();
                rottenQueue.pop();
                for (int i = 0; i < 4; i++) {
                    int newRow = row + dir[i][0];
                    int newCol = col + dir[i][1];

                    if (!checkCanWalk(newRow, newCol, grid)) 
                        continue;
                    grid[newRow][newCol] = 2;
                    freshCount--;
                    rottenQueue.push({newRow, newCol});
                    infected = true;
                }
            }
            // 這層結束
            if (infected) ansTime++;
        }
        if (freshCount != 0) return -1;
        return ansTime;
    }

    bool checkCanWalk(int row, int col, vector<vector<int>>& grid) {
        return row >= 0 
            && row < grid.size() 
            && col >= 0 
            && col < grid[0].size() 
            && grid[row][col] == 1;
    }
};
// @lc code=end

