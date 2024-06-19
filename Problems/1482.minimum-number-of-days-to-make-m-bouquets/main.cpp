/*
 * @lc app=leetcode id=1482 lang=cpp
 *
 * [1482] Minimum Number of Days to Make m Bouquets
 */

// @lc code=start
#define DEBUG
#include <vector>
using namespace std;
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size() < static_cast<long long>(m) * k) {
            return -1;
        }
        // 天數越多，花束的數量一定也越大
        // 因此可以根據花束的結果，對天數做binary search
        int low = 1;
        int high = 1e9;

        while (low < high) {
            int mid = (low + high) / 2;
            int bouquestCount = 0;

            for (int i = 0, count = 0; i < bloomDay.size(); ++i) {
                if (bloomDay[i] <= mid) {
                    count++;
                }
                else {
                    count = 0;
                }
                // 湊到一束
                if (count == k) {
                    bouquestCount++;
                    count = 0;
                }
                // 夠了，直接break
                if (bouquestCount == m) {
                    break;
                }
            }

            if (bouquestCount < m) {
                low = mid + 1;
            }
            else  {
                high = mid;
            }
        }
        return low;
    }
};
#ifdef DEBUG
int main() {
    Solution s;
    int m = 1;
    int k = 1;
    vector<int> bloomDays = {1000000000,1000000000};
    int ans = s.minDays(bloomDays, m, k);
    return 0;
}
#endif
// @lc code=end

