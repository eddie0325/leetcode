/*
 * @lc app=leetcode id=3175 lang=cpp
 *
 * [3175] Find The First Player to win K Games in a Row
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int player1 = 0;
        int player2 = 1;
        int win = 0;
        while(player1 < skills.size() && player2 < skills.size()) {
            if (skills[player1] > skills[player2]) {
                player2++;
            }
            else {
                player1 = player2;
                player2 = player1 + 1;
                win = 0;
            }
            if (++win == k) {
                return player1;
            }
        }
        // 跑完一輪，之後都會是這個最大的人一直贏
        return player1;
    }
};
// @lc code=end

