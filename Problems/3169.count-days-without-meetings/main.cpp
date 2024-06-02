/*
 * @lc app=leetcode id=3169 lang=cpp
 *
 * [3169] Count Days Without Meetings
 */

// @lc code=start
#define DEBUG
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int workdays = 0;
        int nowCheck = 1;

        // 先將全部起點排序
        sort(meetings.begin(), meetings.end());
        for (auto it = meetings.begin(); it != meetings.end(); ++it) {
            int start = it->at(0);
            int end = it->at(1);

            // nowCheck之前的已經都檢查過了
            if (end < nowCheck) {
                continue;
            }
            // 中間有空閒的日子是工作天
            if (start > nowCheck) {
                workdays += (start - nowCheck);
            }
            nowCheck = end + 1;
        }
        
        // 結尾還有空閒的日子是工作天
        workdays += (days - nowCheck) + 1;
        return workdays;
    }
};
#ifdef DEBUG
int main() {
    Solution s;
    vector<vector<int>> meetings = {{2,4},{1,3}};
    int days = s.countDays(5, meetings);
    return days;
}
#endif
// @lc code=end

