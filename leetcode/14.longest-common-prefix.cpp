#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for (string x : strs) {
            while (x.compare(0, prefix.size(), prefix) != 0) {
                prefix.pop_back();
            }
        }
        return prefix;
    }
};
// @lc code=end

