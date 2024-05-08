/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 */

// @lc code=start

// #define DEBUG
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    struct Athelete {
        int score;
        int order;
    };
    vector<string> findRelativeRanks(vector<int>& score) {
        
        // 記錄本來的順序order，來依照分數score排序
        vector<Athelete> atheleteData(score.size());

        for (int i = 0; i < score.size(); i++) {
            atheleteData[i] = Athelete{score[i], i};
        }

        sort(atheleteData.begin(), atheleteData.end(), compareScore);
        
        // 按照分數score，將排名用order填回去
        vector<string> result(atheleteData.size());
        for (int i = 0; i < atheleteData.size(); i++) {
            string rankString = std::to_string(i + 1);
            if (i == 0) {
                rankString = "Gold Medal";
            }
            else if (i == 1) {
                rankString = "Silver Medal";
            }
            else if (i == 2) {
                rankString = "Bronze Medal";
            }
            int index = atheleteData[i].order;
            result[index] = rankString;
        }
        return result;
    }

    static bool compareScore(Athelete a, Athelete b) {
        return a.score > b.score;
    }
};

#ifdef DEBUG
int main() {
    Solution s;
    vector<int> score = {10, 3, 8, 9, 4};
    auto result = s.findRelativeRanks(score);
    return 0;
}
#endif
// @lc code=end

