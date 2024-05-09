/*
 * @lc app=leetcode id=3075 lang=cpp
 *
 * [3075] Maximize Happiness of Selected Children
 */

// @lc code=start

// #define DEBUG

#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // 大到小排序
        
        // slower
        // sort(happiness.rbegin(), happiness.rend()); // 反向迭代器排序
        
        // faster
        sort(begin(happiness), end(happiness), greater<int>());
        
        long long sum = 0;
        int turn = 0; // turn 從0開始編號計算比較方便
        while(k--) {
            // 每過turn回合，取到的happiness值會少了turn的值
            if (happiness[turn] - turn > 0) {
                sum += happiness[turn] - turn;
            }
            // 已經沒有人有happiness值了，提早結束
            else {
                break;
            }
            turn++;
        }
        return sum;
    }
};

#ifdef DEBUG
int main() {
    Solution s;
    vector<int> happiness = {2,3,4,5};
    int k = 1;
    long long ans = s.maximumHappinessSum(happiness, k);
    return 0;
}
#endif
// @lc code=end

