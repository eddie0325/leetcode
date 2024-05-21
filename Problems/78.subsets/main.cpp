/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
#define DEBUG
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // 1 OOOOXXXX
        // 2 OOXXOOXX
        // 3 OXOXOXOX
        vector<vector<int>> result(pow(2, nums.size()), vector<int>());
        int resultSize = result.size();
        int pushCount = resultSize;
        for (int i = 0; i < nums.size(); ++i) {
            pushCount /= 2;
            // 要填的起點位置
            for (int j = 0; j < resultSize; j+=(pushCount * 2)) {
                // 連續填pushCount個
                for (int k = 0; k < pushCount; ++k) {
                    result[j + k].push_back(nums[i]);
                }
            }
            
        }
        return result;
    }
};

#ifdef DEBUG
int main() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    auto result = s.subsets(nums);
    return 0;
}
#endif
// @lc code=end

