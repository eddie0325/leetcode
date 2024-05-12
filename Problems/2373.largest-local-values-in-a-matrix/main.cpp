/*
 * @lc app=leetcode id=2373 lang=cpp
 *
 * [2373] Largest Local Values in a Matrix
 */

// @lc code=start

// #define DEBUG
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int matrixSize = grid.size();
        vector<vector<int>> res(matrixSize - 2, vector<int>(matrixSize - 2, INT_MIN));
        for (int i = 1; i < grid.size() - 1; i++) {
            for (int j = 1; j < grid[i].size() - 1; j++) {
                // 找3x3的最大值
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        res[i - 1][j - 1] = max(res[i - 1][j - 1], grid[i + k][j + l]);
                    }
                }
                
            }
        }
        return res;
    }
};

#ifdef DEBUG
int main() {
    vector<vector<int>> grid = {
        {{9,9,8,1},{5,6,2,6},{8,2,6,4},{6,2,2,2}}
    };
    Solution s;
    auto res = s.largestLocal(grid);
    return 0;
}
#endif
// @lc code=end

