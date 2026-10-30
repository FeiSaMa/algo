#include <vector>
#include <stack>
using namespace std;
/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int lenth = temperatures.size();
        vector<int> ans(lenth, 0);
        stack<int> st;
        for (int i = 0; i < lenth; i++) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                int j = st.top();
                st.pop();
                ans[j] = i - j;
            }
            st.push(i);
        }
        return ans;
    }
};
// @lc code=end

