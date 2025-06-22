/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groupMap;
        for (string str:strs){
            string originStr = str;
            sort(str.begin(), str.end());
            groupMap[str].push_back(originStr);
        }
        vector<vector<string>> ans;
        for (const auto& group: groupMap) {
            ans.push_back(group.second);
        }
        return ans;
    }
};
// @lc code=end

