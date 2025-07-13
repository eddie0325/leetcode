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
        vector<vector<int>> ans;
        vector<int> current;
        backtrack(nums, current, 0, ans);
        return ans;
    }

    void backtrack(const vector<int> &nums, vector<int> &current, int index, vector<vector<int>> &ans) {
        if (index == nums.size()) {
            ans.push_back(current);
            return;
        }
        // 目前這個 index 不選
        backtrack(nums, current, index + 1, ans);
        // 目前這個 index 選
        current.push_back(nums[index]);
        backtrack(nums, current, index + 1, ans);
        // 回朔狀態
        current.pop_back();
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

