/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
// #define DEBUG
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pointerStart = 0;
        int pointerEnd = nums.size() - 1;
        // pointerStart 從頭開始找想交換的
        // pointerEnd 從尾部開始找能被交換的
        while (pointerStart <= pointerEnd) {
            if (nums[pointerEnd] == val) {
                pointerEnd--;
                continue;
            }
            if (nums[pointerStart] != val) {
                pointerStart++;
                continue;
            }
    
            // 交換
            int temp = nums[pointerStart];
            nums[pointerStart] = nums[pointerEnd];
            nums[pointerEnd] = temp;
            pointerStart++;
            pointerEnd--;
        }
        return pointerStart;
    }
};
#ifdef DEBUG
int main() {
    Solution s;
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    int a = s.removeElement(nums, val);
    return 0;
}
#endif
// @lc code=end

