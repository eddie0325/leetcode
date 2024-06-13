/*
 * @lc app=leetcode id=2037 lang=cpp
 *
 * [2037] Minimum Number of Moves to Seat Everyone
 */

// @lc code=start
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(students.begin(), students.end());
        sort(seats.begin(), seats.end());
        int sum = 0;
        for (int i = 0; i < students.size(); i++) {
            sum += abs(seats[i] - students[i]);
        }
        return sum; 
    }
};
// @lc code=end

