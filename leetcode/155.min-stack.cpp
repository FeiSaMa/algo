#include <stack>
using std::stack;
/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
    private:
        stack<int> st;
        stack<int> minst;

    public:
        MinStack() {
            
        }
    
        void push(int value) {
            st.push(value);
            if (!minst.empty() && minst.top() >= value) {
                minst.push(value);
            } else if (!minst.empty() && minst.top() < value) {
                // do nothing
            } else {
                minst.push(value);
            }
        }
    
        void pop() {
            if (st.top() == minst.top()) minst.pop();
            st.pop();
        }
    
        int top() {
            return st.top();    
        }
    
        int getMin() {
            return minst.top(); 
        }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

