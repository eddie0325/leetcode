/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        static const regex intReg = regex("[+-]?[0-9]+");
        for (int i = 0; i < tokens.size(); i++) {
            if (regex_match(tokens[i], intReg))
                nums.push(stoi(tokens[i]));
            else {
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();
                nums.push(calc(num1, num2, tokens[i]));
            }
        }
        return nums.top();
    }

    int calc(int a, int b, const string &c) {
        if (c == "+")
            return a + b;
        else if (c == "-")
            return a - b;
        else if (c == "*")
            return a * b;
        else
            return a / b;
    }
};
// @lc code=end

