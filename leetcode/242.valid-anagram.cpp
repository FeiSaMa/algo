#include <string>
using namespace std;
/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        int cnt[26] {};
        
        for (int i = 0; i < (int) s.size(); i++) {
            cnt[s[i] - 'a']++;
        }
        
        for (int j = 0; j < (int) t.size(); j++) {
            cnt[t[j] - 'a']--;
        }
        
        for (int k = 0; k < 26; k++) {
            if (cnt[k] != 0) return false;
        }
        return true;
    }
};
// @lc code=end

