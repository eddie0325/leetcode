/*
 * @lc app=leetcode id=778 lang=cpp
 *
 * [778] Swim in Rising Water
 */

// @lc code=start
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        auto cmp = [](pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b) {
            return a.first > b.first;
        };
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(cmp)> minHeap(cmp);
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        int level = 0;
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        minHeap.push({grid[0][0], {0, 0}});
        while(!minHeap.empty()) {
            auto [cost, p] = minHeap.top();
            auto [x, y] = p;
            minHeap.pop();

            visited[x][y] = true;
            level = max(level, cost);

            if (x == n - 1 && y == n - 1) break;

            // 把四周的加進heap
            for (int i = 0; i < 4; i++) {
                int newX = x + dir[i][0];
                int newY = y + dir[i][1];
                if (newX >=0 && newX < n && newY >=0 && newY < n && !visited[newX][newY]) {
                    minHeap.push({grid[newX][newY], {newX, newY}});
                }
                
            }
        }
        return level;
    }
};
// @lc code=end

