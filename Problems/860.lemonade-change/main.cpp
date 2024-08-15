/*
 * @lc app=leetcode id=860 lang=cpp
 *
 * [860] Lemonade Change
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution 
{
public:
    bool lemonadeChange(vector<int>& bills) {
        int charges[] = {0, 0}; // 5元跟10元的數量，20不能用來找錢
        for (int i = 0; i < bills.size(); ++i) {
            if (bills[i] == 5) {
                charges[0]++;
            }
            else if (bills[i] == 10) {
                if (charges[0] > 0) {
                    charges[0]--;
                    charges[1]++;
                }
                else {
                    return false;
                }
            }
            else {
                if (charges[1] > 0 && charges[0] > 0) {
                    charges[1]--;
                    charges[0]--;
                }
                else if (charges[0]> 2) {
                    charges[0]-=3;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

