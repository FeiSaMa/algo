#include <string>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
class Solution {
private:
    int cnt[128];
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int n = (int) s.size();
        for (int right = 0; right < n; right++) {
            cnt[s[right]]++;
        }
    }
};
// @lc code=end

