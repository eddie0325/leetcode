/*
 * @lc app=leetcode id=1051 lang=cpp
 *
 * [1051] Height Checker
 */

// @lc code=start
#define DEBUG
#include <vector>
using namespace std;
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        // counting sort
        int count[101];
        int ans = 0;
        memset(count, 0, sizeof(count));
        for (int i = 0; i < heights.size(); ++i) {
            count[heights[i]]++;
        }

        // 來比對有多少內容跟排序的不一樣
        int pointerA = 0;
        int pointerB = 0;
        while(pointerA < 101 && pointerB < heights.size()) {
            for (int i = 0; i < count[pointerA]; ++i) {
                if (heights[pointerB++] != pointerA) {
                    ans++;
                }
            }
            pointerA++;
        }

        return ans;
    }
};
#ifdef DEBUG
int main() {
    Solution s;
    vector<int> heights = {1,1,1,1,1,1,1,1};
    int ans = s.heightChecker(heights);
    return 0;
}
#endif
// @lc code=end

