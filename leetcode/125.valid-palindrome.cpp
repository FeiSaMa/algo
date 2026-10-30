#include <string>
using namespace std;
/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = (int) s.size() - 1;

        while (left < right) {
            while (left < right && !isNumOrChar(s[left])) left++;
            while (left < right && !isNumOrChar(s[right])) right--;
            if (upperToLower(s[left]) != upperToLower(s[right])) return false;
            left++;
            right--;
        }
        return true;
    }
    bool isNumOrChar(char c) {
        if (c <= '9' && c >= '0') return true;
        else if (c <= 'z' && c >= 'a' || c <= 'Z' && c >= 'A') return true;
        else return false;
    }
    char upperToLower(char c) {
        if (c <= 'Z' && c >= 'A') c += ('a' - 'A');
        return c;
    }
};
// @lc code=end

