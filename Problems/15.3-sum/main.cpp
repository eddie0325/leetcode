/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int first = 0; first < nums.size() - 2; first++) {
            // 後面已不可能有解
            if (nums[first] > 0) break;
            if (first > 0 && nums[first] == nums[first - 1]) continue;

            int target = -nums[first];
            int i = first + 1;
            int j = nums.size() - 1;
            while(i < j) {
                int sum = nums[i] + nums[j];
                if (sum < target) i++;
                else if (sum > target) j--;
                else {
                    ans.push_back({nums[first], nums[i], nums[j]});
                    while(i < j && nums[i] == nums[i + 1]) i++;
                    while(i < j && nums[j] == nums[j - 1]) j--;
                    i++;
                    j--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

