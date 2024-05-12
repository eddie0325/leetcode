/*
 * @lc app=leetcode id=786 lang=cpp
 *
 * [786] K-th Smallest Prime Fraction
 */

// @lc code=start

// #define DEBUG
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        double left = 0, right = 1, mid;
        int answerLeft = 0, answerRight = 1;
        int arrlength = arr.size();
    
        while (left < right) {
            mid = (left + right) / 2;
            // 找小於mid的有幾個，目標k個
            int count = 0;
            // 找比值<mid且最接近mid
            double maxFraction = 0;

            for (int i = 0; i < arrlength; i++) {
                for (int j = i + 1; j < arrlength; j++) {
                    double fraction = (double)arr[i] / (double)arr[j];
                    // 後面分母會越來越大，所以比值都會比mid小
                    if (fraction <= mid) {
                        count += (arrlength - j);
                        if (fraction > maxFraction) {
                            maxFraction = fraction;
                            answerLeft = i;
                            answerRight = j;
                        }
                        break;
                    }
                }
                // 如果已經超過k了，後面不用再計算了
                if (count > k) {
                    break;
                }
            }
            if (count == k) {
                break;
            }

            // 重新設定目標比值
            if (count > k) {
                right = mid;
            }
            else {
                left = mid;
            }
        }

        return vector<int>{arr[answerLeft], arr[answerRight]};
    }
};

#ifdef DEBUG
int main() {
    Solution s;
    vector<int> arr = {1, 2, 3, 5};
    int k = 3;
    auto res = s.kthSmallestPrimeFraction(arr, k);
    return 0;
}
#endif
// @lc code=end

