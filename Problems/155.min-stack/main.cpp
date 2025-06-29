/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {

    private:
    stack<int> normalStack;
    // 把當下的min都記錄起來
    stack<int> minStack;

public:
    MinStack() {

    }

    void push(int val) {
        normalStack.push(val);
        int minValue = val;
        if (!minStack.empty())
        {
            minValue = min(minStack.top(), minValue);
        }
        minStack.push(minValue);
    }
    
    void pop() {
        normalStack.pop();
        minStack.pop();
    }
    
    int top() {
        return normalStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

