/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */

// @lc code=start

// #define DEBUG

#include <string>
using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) {
        while(version1 != "" || version2 != "") {
            string revisionString;
            int revision1 = 0;
            int revision2 = 0;
            
            // 計算一號的revivision
            revisionString = version1;
            // 如果還有.後面，就只取前面來計算
            size_t pos1 = version1.find(".");
            if (revisionString != "") {
                if (pos1 != string::npos) {
                    revisionString = revisionString.substr(0, pos1);
                }
                revision1 = stoi(revisionString);
            }
            
            // 計算二號的revivision
            revisionString = version2;
            size_t pos2 = version2.find(".");
            if (revisionString != "") {
                if (pos2 != string::npos) {
                    revisionString = revisionString.substr(0, pos2);
                }
                revision2 = stoi(revisionString);
            }

            if (revision1 > revision2) {
                return 1;
            } else if (revision1 < revision2) {
                return -1;
            }

            // 判斷還有沒有.在後面
            if (pos1 != string::npos) {
                version1 = version1.substr(pos1 + 1);
            }
            else {
                version1 = "";
            }
            if (pos2 != string::npos) {
                version2 = version2.substr(pos2 + 1);
            }
            else {
                version2 = "";
            }

        }
        return 0;
    }
};

#ifdef DEBUG
int main() {
    Solution s;
    int ans;
    ans = s.compareVersion("1.2", "1.10");
    ans = s.compareVersion("1.01", "1.001");
    ans = s.compareVersion("1.0", "1.0.0.0");
    ans = s.compareVersion("1", "1.1");
    return 0;
}
#endif
// @lc code=end

