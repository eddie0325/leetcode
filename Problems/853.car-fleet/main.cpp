/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */

// @lc code=start
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> positionArriveSet;
        int fleets = 0;
        for (int i = 0; i < position.size(); i++) {
            positionArriveSet.push_back({position[i], (double)(target - position[i]) / (double)speed[i]});
        }
        // 依照離終點的距離排序，近排到遠
        sort(positionArriveSet.rbegin(), positionArriveSet.rend());
        double lastTime = 0;
        for (auto& [pos, time]: positionArriveSet) {
            if (time > lastTime) { // 比前車晚到，自成一個fleet
                fleets++;
                lastTime = time;
            }
            // 比前車早到的，會被前車卡住，併入前車的fleet
        }
        return fleets;
    }
};
// @lc code=end

