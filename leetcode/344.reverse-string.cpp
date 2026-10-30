#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = (int) s.size();
        for (int i = 0; i < n / 2; i++) {
            swapItem(s[i], s[n - i - 1]);
        }
    }
    void swapItem(char& a, char& b) {
        char c = a;
        a = b;
        b = c;
    }
};
// @lc code=end

