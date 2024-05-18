/*
 * @lc app=leetcode id=3147 lang=cpp
 *
 * [3147] Taking Maximum Energy From the Mystic Dungeon
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        // 從該點出發，能拿到的能量值
        int dp[energy.size()];
        int maxEnergy = -1001;
        for (int i = energy.size() - 1; i >= 0; i--) {
            dp[i] = energy[i];
            if (i + k < energy.size()) {
                dp[i] += dp[i + k];
            }
            maxEnergy = max(maxEnergy, dp[i]);
        }
        return maxEnergy;
    }
};
// @lc code=end

