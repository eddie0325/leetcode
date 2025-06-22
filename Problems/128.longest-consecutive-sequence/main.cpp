/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        // 連續整數序列，順序不計，剛好差1
        unordered_set<int> numSet(nums.begin(), nums.end());

        for (int num: numSet) {
            // 只找起點
            if (numSet.count(num - 1)) continue;
            int now = num;
            int length = 1;
            while(numSet.count(++now)){
                length++;
            }
            ans = max(length, ans);
        }
        return ans;
    }
};
// @lc code=end

