/*
 * @lc app=leetcode id=3154 lang=cpp
 *
 * [3154] Find Number of Ways to Reach the K-th Stair
 */

// @lc code=start
#define DEBUG
#include <cmath>
#include <vector>
using namespace std;
class Solution {
public:
    // void go(int now, int jump, int target, int lastOp, int &ans) {
    //     if (now == target) {
    //         ans++;
    //     }
    //     // 上一動是退，這動只能跳
    //     if (lastOp == 0) {
    //         int newPos = now + pow(2, jump++);
    //         if (newPos - target > 1) {
    //             return;
    //         }
    //         go(newPos, jump, target, 1, ans);
    //     }
    //     // 上一動是跳，這動可以退或跳
    //     else {
    //         int newPos = now - 1;
    //         go(newPos, jump, target, 0, ans);
            
    //         newPos = now + pow(2, jump++);
    //         if (newPos - target > 1) {
    //             return;
    //         }
    //         go(newPos, jump, target, 1, ans);
    //     }

    // }

    // int waysToReachStair(int k) {
    //     // op 0 down, 1 jump
    //     int ans = 0;
    //     go(1, 0, k, 1, ans);

    //     return ans;
    // }

    // Cn取m
    int binomialCoefficient(int n, int m) {
        vector<vector<int>> C(n + 1, vector<int>(m + 1, 0));
        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= std::min(i, m); j++) {
                // 基本情况
                if (j == 0 || j == i)
                    C[i][j] = 1;
                else
                    C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
        
        return C[n][m];
    }
    int waysToReachStair(int k) {
        // jumpOffset 1 + 2 + 4... = 2^(jumpCount) - 1
        // k = 1(Initial) + 2^(jumpCount) - 1 - downCount
        // downCount最多只能有jumpCount + 1次
        // 在一些較小的k，jumpCount不會是唯一
        int downCount = 0, jumpCount = 0, ans = 0;

        int sum = 1;
        for (int i = 0; i < 30; ++i) {
            if (i > 0)
                sum += pow(2, i - 1);
            if (sum >= k) {
                jumpCount = i;
                downCount = pow(2, jumpCount) - k;
                if (downCount - jumpCount > 1) {
                    break;
                }
                // 在jumpCount + 1個空位，要塞downCount個
                ans += binomialCoefficient(jumpCount + 1, downCount);
            }
        }

        return ans;
    }
};
#ifdef DEBUG
int main() {
    Solution s;
    int ans = s.waysToReachStair(2);
    /*
    1 0 1 0 2 d j d j
    1 0 1 3 2 d j j d
    1 2 j
    1 2 1 3 2 j d j d
    */
    return 0;
}
#endif
// @lc code=end

