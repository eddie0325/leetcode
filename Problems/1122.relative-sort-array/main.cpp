/*
 * @lc app=leetcode id=1122 lang=cpp
 *
 * [1122] Relative Sort Array
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // counting sort
        int bucket[1001];
        int elementCount = arr1.size();
        memset(bucket, 0, sizeof(bucket));
        for (int i = 0; i < elementCount; ++i) {
            bucket[arr1[i]]++;
        }

        int index = 0;
        for (int i = 0; i < arr2.size(); ++i) {
            int target = arr2[i];
            int count = bucket[target];
            while(count--) {
                arr1[index++] = target;
            }
            bucket[target] = 0;
        }
        // 剩下的元素
        for (int i = 0; i < 1001 && index < elementCount; ++i) {
            int count = bucket[i];
            while(count--) {
                arr1[index++] = i;
            }
        }
        return arr1;
    }
};
// @lc code=end

