#include <string>
using std::string;
/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        char* head1 = &haystack[0];
        char* head2 = &needle[0];
        char* p1 = &haystack[0];
        char* p2 = &needle[0];

        for (char* start = head1; *start != '\0'; start++) {
            p1 = start;
            p2 = head2;
            while (*p2 != '\0' && *p1 == *p2) {
                p1++;
                p2++;
            }
            if (*p2 == '\0') return start - head1;
        }
        return -1;
    }
};
// @lc code=end

