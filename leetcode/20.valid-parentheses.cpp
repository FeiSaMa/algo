#include <stack>
#include <string>
using std::string;
/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        int num = s.size();
        std::stack<char> sta;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                sta.push(c);
            } else {
                if (sta.empty()) {
                    return false;
                } else {
                    char top_char = sta.top();
                    sta.pop();
                    if ((c == ')' && top_char != '(') ||
                        (c == ']' && top_char != '[') ||
                        (c == '}' && top_char != '{')) {
                            return false;
                        }
                }
            }
        }
        return sta.empty();
    }
};
// @lc code=end

