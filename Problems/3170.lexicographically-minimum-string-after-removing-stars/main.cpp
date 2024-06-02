/*
 * @lc app=leetcode id=3170 lang=cpp
 *
 * [3170] Lexicographically Minimum String After Removing Stars
 */

// @lc code=start
// #define DEBUG
#include <string>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    // 先找最小char，相同的話找最右邊的
    struct compareFunction {
        bool operator()(const pair<char, int>& a, const pair<char, int>& b) const {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        }
    };

    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, compareFunction> minHeap;
        vector<int> indexes;
        string result;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != '*') {
                minHeap.push({s[i], i});
            }
            else {
                indexes.push_back(minHeap.top().second);
                minHeap.pop();
            }
        }
        // 把應該delete的都先變成*
        for (int i = 0; i < indexes.size(); ++i) {
            s[indexes[i]] = '*';
        }
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != '*') {
                result += s[i];
            }
        }
        return result;
    }
};
#ifdef DEBUG
int main() {
    Solution s;
    string ans = s.clearStars("aaba*");
    return 0;
}
#endif
// @lc code=end

