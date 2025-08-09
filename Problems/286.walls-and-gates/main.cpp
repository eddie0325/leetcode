// from NeetCode
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> cellsQueue;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 0) {
                    cellsQueue.push({i, j});
                }
                    
            }
        }
        bfs(cellsQueue, grid);
    }

    void bfs(queue<pair<int, int>> cells, vector<vector<int>>& grid) {
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!cells.empty()) {
            auto [row, col] = cells.front();
            cells.pop();
            int distance = grid[row][col] + 1;
            for (int i = 0; i < 4; i++) {
                int newRow = row + dir[i][0];
                int newCol = col + dir[i][1];
                if (!checkCanWalk(newRow, newCol, grid)) 
                    continue;
                if (grid[newRow][newCol] > distance) {
                    grid[newRow][newCol] = distance;
                    cells.push({newRow, newCol});
                }
            }
        }
    }

    bool checkCanWalk(int row, int col, vector<vector<int>>& grid) {
        if(row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size()) {
            return grid[row][col] != -1;
        }
        return false;
    }
};
