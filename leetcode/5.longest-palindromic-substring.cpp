#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    // ★ 入口：LeetCode 只调这个。推荐解 = 中心扩展（O(n^2) 时间 / O(1) 空间）
    string longestPalindrome(string s) {
        return longestPalindromeCE(s);
    }

    string longestPalindromeDP(string s) {
        int n = s.size();
        if (n == 0) return "";
        // dp[i][j]，下标为(i, j)之间是否为回文子串
        vector<vector<bool>> dp(n, vector<bool>(n));
        int maxLen = 1;
        int start = 0;
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && (len <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    if (len > maxLen) {
                        maxLen = len;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
    string longestPalindromeCE(string s) {
        int n = s.size();
        if (n == 0) return "";
        int maxLen = 1;
        int start = 0;
        for (int c = 0; c < 2 * n - 1; c++) {
            int l, r;
            if (c % 2 == 0) {
                // c_max = 2 * (n - 1)
                l = c / 2; // odd center
                r = l;
                while (l >= 0 && r < n && s[l] == s[r]) {
                    int len = r - l + 1;
                    if (len > maxLen) {
                        maxLen = len;
                        start = l;
                    }
                    r++; l--;
                } 
                
            } else {
                // c_max = 2 * n - 3 = 2 * (n - 1) - 1
                l = c / 2; // even center
                r = l + 1;
                while (l >= 0 && r < n && s[l] == s[r]) {
                    int len = r - l + 1;
                    if (len > maxLen) {
                        maxLen = len;
                        start = l;
                    }
                    r++; l--;
                }
            }
        }
        
        return s.substr(start, maxLen);
    }
};
// @lc code=end

