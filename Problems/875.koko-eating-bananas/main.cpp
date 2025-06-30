/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 1;
        int ans = INT_MAX;
        for (int pile: piles)
            right = max(right, pile);

        while(left <= right) {
            int mid = left + (right - left) / 2;
            int hourNeed = 0;
            for (int pile: piles) {
                hourNeed += pile / mid;
                if (pile % mid != 0)
                    hourNeed++;
                if (hourNeed > h)
                    break;
            }
            if (hourNeed > h)
                left = mid + 1;
            else {
                ans = min(ans, mid);
                right = mid - 1;
            }
        }
        return ans;
    }
};
// @lc code=end

