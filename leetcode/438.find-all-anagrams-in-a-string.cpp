#include <string>
#include <vector>
using std::string, std::vector;
/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) return {};

        int char_s[26] {};
        int char_p[26] {};
        
        for (int i = 0; i < (int)p.size(); i++) {
            char_p[p[i] - 'a']++;
        }
        
        for (int i = 0; i < (int)p.size(); i++) {
            char_s[s[i] - 'a']++;
        }
        
        vector<int> indices;
        int start{};
        for (int end = (int)p.size(); end < (int)s.size(); end++) {
            if (isEqual(char_s, char_p)) indices.push_back(start);
            char_s[s[end] - 'a']++;
            char_s[s[start] - 'a']--;
            start++;
        }
        if (isEqual(char_s, char_p)) indices.push_back(start);
        return indices;
    }
    bool isEqual(const int* a, const int* b) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }
};
// @lc code=end

