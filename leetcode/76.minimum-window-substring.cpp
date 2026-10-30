#include <climits>
#include <string>
using std::string;
/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        int l_s = (int)s.size();
        int l_t = (int)t.size();
        if (l_t > l_s) return "";

        int s_char_count[128] {};
        int t_char_count[128] {};
        
        for (int i = 0; i < l_t; i++) {
            t_char_count[t[i]]++;
        }

        int start{};
        int l_window{};
        int min_l_window = INT_MAX;
        int f_start{};
        int f_end{};
        for (int end = 0; end < l_s; end++) {
            s_char_count[s[end]]++;
            while (isMathed(s_char_count, t_char_count)) {
                l_window = end - start + 1;
                if (l_window < min_l_window) {
                    min_l_window = l_window;
                    f_start = start;
                    f_end = end;
                }
                s_char_count[s[start]]--;
                start++; 
            }
        }
        
        if (min_l_window == INT_MAX) return "";
        return s.substr(f_start, min_l_window);
    }

    bool isMathed(int* s, int* t) {
        for (int i = 0; i < 128; i++) {
            if (s[i] < t[i]) return false;
        }
        return true;
    }
};
// @lc code=end

