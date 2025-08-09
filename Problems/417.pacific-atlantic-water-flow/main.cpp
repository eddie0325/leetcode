/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int w = heights[0].size();
        int h = heights.size();
        vector<vector<bool>> pacificVisited(h, vector<bool>(w, false));
        vector<vector<bool>> atlanticVisited(h, vector<bool>(w, false));
        
        // Pacific 上排+左排
        queue<pair<int, int>> pacificQueue;
        for (int i = 0; i < w; i++) {
            pacificQueue.push({0, i});
            pacificVisited[0][i] = true;
        }
        for (int i = 0; i < h; i++) {
            pacificQueue.push({i, 0});
            pacificVisited[i][0] = true;
        }
        
        // Atlantic 右排+下排
        queue<pair<int, int>> atlanticQueue;
        for (int i = 0; i < w; i++){
            atlanticQueue.push({h - 1, i});
            atlanticVisited[h - 1][i] = true;
        } 
        for (int i = 0; i < h; i++) {
            atlanticQueue.push({i, w - 1});
            atlanticVisited[i][w - 1] = true;
        }
        
        bfs(pacificQueue, pacificVisited, heights);
        bfs(atlanticQueue, atlanticVisited, heights);

        vector<vector<int>> ans;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (pacificVisited[i][j] && atlanticVisited[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }

    void bfs(queue<pair<int, int>>& queue, vector<vector<bool>> &visitedMap, vector<vector<int>>& heights) {
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!queue.empty()) {
            auto [row, col] = queue.front();
            queue.pop();

            for (int i = 0; i < 4; i++) {
                int newRow = row + dir[i][0];
                int newCol = col + dir[i][1];
                if (!checkBound(newRow, newCol, heights))
                    continue;
                if (visitedMap[newRow][newCol])
                    continue;
                // new node can flow into origin node
                if (heights[row][col] <= heights[newRow][newCol]) {
                    queue.push({newRow, newCol});
                    visitedMap[newRow][newCol] = true;    
                }
            }
        }
    }

    bool checkBound(int row, int col, vector<vector<int>>& heightMap) {
        int w = heightMap[0].size();
        int h = heightMap.size();
        return row >= 0
            && row < h
            && col >= 0
            && col < w;
    }
};
// @lc code=end

