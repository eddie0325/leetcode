/*
 * @lc app=leetcode id=3148 lang=cpp
 *
 * [3148] Maximum Difference Score in a Grid
 */

// @lc code=start
#define DEBUG
#include <vector>
using namespace std;
class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int maxScore = INT_MIN;
        int width = grid[0].size();
        int height = grid.size();
        
        // 過程不重要，會被抵銷
        // c1 -> c3 = (c2 - c1) + (c3 - c2) = c3 - c1
        // 找出該格之左上最小值，更新該格供後面dp使用
        // grid新定義，grid[i][j]為grid ixj的最小值
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                int minValue = INT_MAX;
                if (i == 0 && j == 0) {
                    continue;
                }
                // 找出上面還是左邊比較小
                if (i != 0) {
                    minValue = min(minValue, grid[i - 1][j]);
                }
                if (j != 0) {
                    minValue = min(minValue, grid[i][j - 1]);
                }
                
                maxScore = max(maxScore, grid[i][j] - minValue);
                // 更新grid
                grid[i][j] = min(grid[i][j], minValue);
            }
        }

        return maxScore;
    }
};
#ifdef DEBUG
int main() {
    Solution s;
    vector<vector<int>> grid = {{9,5,7,3},{8,9,6,1},{6,7,14,3},{2,5,3,1}};
    // vector<vector<int>> grid = {{4,3,2},{3,2,1}};
    
    int aaa =  s.maxScore(grid);
    return 0;
}
#endif
// @lc code=end

