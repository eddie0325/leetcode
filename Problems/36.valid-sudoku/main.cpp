/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // bool rule1[9][9] = {false}; // row 
        // bool rule2[9][9] = {false}; // column
        // bool rule3[9][9] = {false}; // square
        // for (int i = 0; i < 9; i++)
        //     for (int j = 0; j < 9; j++) {
        //         if (board[i][j] == '.') continue;
        //         int num = board[i][j] - '1';
        //         // rule1
        //         if (rule1[i][num])
        //             return false;
        //         rule1[i][num] = true;

        //         // rule2
        //         if (rule2[j][num])
        //             return false;
        //         rule2[j][num] = true;

        //         // rule3
        //         int seq = (i / 3) * 3 + j / 3;
        //         if (rule3[seq][num])
        //             return false;
        //         rule3[seq][num] = true;
        //     }
        // return true;

        // bitmask
        int rule1[9] = {0}; // row 
        int rule2[9] = {0}; // column
        int rule3[9] = {0}; // square
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '1';
                int bit = 1 << num;

                int seq = (i / 3) * 3 + j / 3;

                if (rule1[i] & bit || rule2[j] & bit || rule3[seq] & bit)
                    return false;
                rule1[i] |= bit;
                rule2[j] |= bit;
                rule3[seq] |= bit;
            }
        return true;
    }
};
// @lc code=end

