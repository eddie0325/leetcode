/*
 * @lc app=leetcode id=1550 lang=cpp
 *
 * [1550] Three Consecutive Odds
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int consecutiveOdds = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] % 2 == 1) {
                if (++consecutiveOdds == 3) {
                    return true;
                }
            }
            else {
                consecutiveOdds = 0;
            }
        }
        return false;
    }
};
// @lc code=end

