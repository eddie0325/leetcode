/*
 * @lc app=leetcode id=3152 lang=cpp
 *
 * [3152] Special Array II
 */

// @lc code=start
#define DEBUG

#include <vector>
using namespace std;
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        //計算change次數，再比較起點跟終點的change次數是否相同
        vector<int> changeCountVector(1, 0);
        int n = nums.size();
        int changeCount = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] % 2 == nums[i -1] % 2) {
                changeCount++;
            }
            changeCountVector.push_back(changeCount);
        }

        vector<bool> result;
        for (auto query : queries) {
            result.push_back(changeCountVector[query[0]] == changeCountVector[query[1]]);
        }
        return result;
    }
};

#ifdef DEBUG
int main() {
    Solution s;
    vector<int> nums = {3,4,1,2,6};
    vector<vector<int>> queries = {
        {0, 4}
    };
    vector<bool> result = s.isArraySpecial(nums, queries);
    return 0;
}
#endif
// @lc code=end

