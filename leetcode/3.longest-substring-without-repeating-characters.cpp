#include <string>
using std::string;
/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // last[c] = last seen index of character c, -1 if unseen
        int last[128];
        for (int i = 0; i < 128; i++) last[i] = -1;

        int best = 0;
        int left = 0;  // window is s[left, right]
        for (int right = 0; right < (int)s.size(); right++) {
            unsigned char c = s[right];
            if (last[c] >= left) {
                left = last[c] + 1;
            }
            last[c] = right;
            best = (best > right - left + 1) ? best : (right - left + 1);
        }

        return best;
    }
};
// @lc code=end

