/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> elementCount;
        int maxCount = 0;
        vector<int> ans;
        for(int num:nums) {
            elementCount[num]++;
            maxCount = max(maxCount, elementCount[num]);
        }
        vector<vector<int>> bucket(maxCount + 1);
        for (const auto& elements: elementCount){
            bucket[elements.second].push_back(elements.first);
        }
        for (int i = maxCount; i >= 0 && k > 0; i--) {
            if (bucket[i].size() > 0) {
                for (int num: bucket[i]) {
                    ans.push_back(num);
                    if (--k == 0)
                        break;
                } 
            }
        }
        return ans;
    }
};
// @lc code=end

