/*
 * @lc app=leetcode id=945 lang=cpp
 *
 * [945] Minimum Increment to Make Array Unique
 */

// @lc code=start
#define DEBUG
#include <vector>
using namespace std;
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int sum = 0;
        int bucket[200001];

        // 紀錄下一個可能的空值位置
        // memset(bucket, -1, sizeof(bucket));
        // for (int i = 0; i < nums.size(); ++i) {
        //     int target = nums[i];
        //     while(bucket[target] >= 0) {
        //         // 如果這格已經有人了，上面的數字是可能的空格值
        //         sum += bucket[target] - target;
        //         target = bucket[target];
        //     }
        //     // 把找到的格字跟起始都記錄成目前的下一格
        //     // 他是可能的空格值
        //     bucket[target] = target + 1;
        //     bucket[nums[i]] = target + 1;
        // }

        // 全部先放好，再從小到大把多的給後面 
        memset(bucket, 0, sizeof(bucket));
        int minValue = 100000;
        int totalCount = nums.size();
        for (int i = 0; i < totalCount; ++i) {
            bucket[nums[i]]++;
            minValue = min(minValue, nums[i]);
        }

        for (int i = minValue, nowCount = 0; nowCount < totalCount; ++i) {
            if (bucket[i] <= 1) {
                nowCount += bucket[i];
                continue;
            }
            // 把多餘的放到後面
            int toomany = bucket[i] - 1;
            bucket[i + 1] += toomany;
            sum += toomany;
            nowCount++;
        }
        return sum;
    }
};
#ifdef DEBUG
int main() {
    Solution s;
    vector<int> nums = {9,9,10,10,10,10,10,10,10,10};
    int a = s.minIncrementForUnique(nums);
    return 0;
}
#endif
// @lc code=end

