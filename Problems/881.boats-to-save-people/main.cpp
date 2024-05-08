/*
 * @lc app=leetcode id=881 lang=cpp
 *
 * [881] Boats to Save People
 */

// @lc code=start

// #define DEBUG
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    // TLE
    // int numRescueBoats(vector<int>& people, int limit) {
    //     int result = 0;
    //     // 先排序
    //     sort(people.begin(), people.end());
    //     // 直到所有人都上船
    //     while (people.size() > 0) {
    //         // 幫最大的j找最適合的夥伴
    //         int partner = -1;
    //         int i = 0, j = people.size() - 1;
    //         for (i = 0; i < j; i++) {
    //             if (people[i] + people[j] <= limit) {
    //                 partner = i;
    //             }
    //         }

    //         // 有找到，兩人一起上船
    //         if (partner != -1) {
    //             people.erase(people.begin() + j);
    //             people.erase(people.begin() + partner);
    //         }
    //         // 沒有找到，j自己上船
    //         else {
    //             people.erase(people.begin() + j);
    //         }
    //         result++;
    //     }
    //     return result;
    // }

    int numRescueBoats(vector<int>& people, int limit) {
        int result = 0;
        // 先排序
        sort(people.begin(), people.end());

        int i = 0, j = people.size() - 1;
        // i,j 兩個pointer重疊
        while (i <= j) {
            // 最大配最小就好了，沒成功就j自己上船
            if (people[i] + people[j] <= limit) {
                // i上船
                i++;
            }
            // j上船
            j--;
            result++;
        }
        return result;
    }
};

#ifdef DEBUG
int main() {
    Solution s;
    vector<int> people = {6, 6};
    int limit = 7;
    int result =  s.numRescueBoats(people, limit);
    return 0;
}
#endif
// @lc code=end

