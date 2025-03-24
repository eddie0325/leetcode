/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
// #KEYPOINT Boyer–Moore majority vote algorithm
#include <vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int answer = 1000000001;
        int count = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (answer != nums[i]) {
                count --;
                if (count == 0) {
                    answer = nums[i];
                    count = 1;
                }
            }
            else {
                count ++;
            }
        }
        
        return answer;
    }
};
// @lc code=end

