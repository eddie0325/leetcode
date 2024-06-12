/*
 * @lc app=leetcode id=2597 lang=cpp
 *
 * [2597] The Number of Beautiful Subsets
 */

// @lc code=start
// #KEYPOINT backtracking
#define DEBUG
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    // int beautifulSubsets(vector<int>& nums, int k) {
    //    int sum = 0;

    //    for (int i = 0; i < nums.size(); i++) {
    //         backtrack(nums[i], vector<int>(nums.begin() + i + 1, nums.end()), k, sum);
    //     }
    //     return sum;
    // }

    // void backtrack(int pick, vector<int> unused, int k, int& sum) {
    //     if (unused.size() == 0) {
    //         sum++;
    //         return;
    //     }
    //     vector<int> subVector;
    //     for (int i = 0; i < unused.size(); i++) {
    //         if (abs(unused[i] - pick) != k) {
    //             subVector.push_back(unused[i]);
    //         }
    //     }
    //     sum++;
    //     for (int i = 0; i < subVector.size(); i++) {
    //         backtrack(subVector[i], vector<int>(subVector.begin() + i + 1, subVector.end()), k, sum);
    //     }
    // }

    int sum = 0;
    int visited[1001] = {0};

    int beautifulSubsets(vector<int>& nums, int k) {
        int size = nums.size();
        // 排序，這樣只要往前檢查就好
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, size, k);
        sum -=1; // 空set
        return sum;
    }

    void backtrack(vector<int> &nums, int now, int size, int k) {
        // 走到終點了
        if (now == size) {
            sum++;
            return;
        }

        int nowNumber = nums[now];
        // pick條件
        if (nowNumber < k || visited[nowNumber - k] == 0) {
            // 有選
            visited[nowNumber]++;
            backtrack(nums, now + 1, size, k);
            visited[nowNumber]--;
        }
        // 沒選
        backtrack(nums, now + 1, size, k);
    }
};

#ifdef DEBUG
int main() {
    Solution s;
    vector<int> nums = {2,4,6};
    int k = 2;
    auto ans = s.beautifulSubsets(nums, k);
    return 0;
}
#endif

// @lc code=end

