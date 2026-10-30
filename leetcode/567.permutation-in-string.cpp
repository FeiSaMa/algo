#include <string>
using namespace std;
/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        int c_s1[128] {};
        int c_s2[128] {};

        for (int i = 0; i < (int)s1.size(); i++) {
            c_s1[s1[i]]++;
        }

        int k = (int)s1.size();
        for (int i = 0; i < k; i++) {
            c_s2[s2[i]]++;
        }

        int start{};
        for (int end = k; end < (int)s2.size(); end++) {
            if (isEqual(c_s1, c_s2)) return true;
            c_s2[s2[end]]++;
            c_s2[s2[start]]--;
            start++; 
        }
        if (isEqual(c_s1, c_s2)) return true;
        return false;
    }
    
    bool isEqual(const int* c1, const int* c2) {
        for (int i = 0; i < 128; i++) {
            if (c1[i] != c2[i]) return false;
        }
        return true;
    }
};
// @lc code=end

