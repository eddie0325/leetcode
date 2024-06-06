/*
 * @lc app=leetcode id=846 lang=cpp
 *
 * [846] Hand of Straights
 */

// @lc code=start
// #define DEBUG
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        unordered_map<int, int> count;
        sort(hand.begin(), hand.end());
        for (auto i : hand)
        {
            count[i]++;
        }
        // 從最小的開始找
        // 找x~x+groupSize-1
        // 看數量夠不夠湊組
        for (int i = 0; i < hand.size(); ++i)
        {
            if (count[hand[i]] == 0)
            {
                continue;
            }

            int groupCount = count[hand[i]];
            for (int j = 0; j < groupSize; ++j)
            {
                int nextNumber = hand[i] + j;
                if (count[nextNumber] < groupCount)
                {
                    return false;
                }
                count[nextNumber] -= groupCount;
            }
            // i 往後跳，加速
            i += groupCount - 1;
        }
        return true;
    }
};
#ifdef DEBUG
int main()
{
    Solution s;
    vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    int groupSize = 3;
    bool ans = s.isNStraightHand(hand, groupSize);
    return 0;
}
#endif
// @lc code=end
