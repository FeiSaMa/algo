#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int index_g = 0; // g < g.size()
        int index_s = 0; // s < s.size()

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int count{};
        while (index_g < (int) g.size() && index_s < (int) s.size()) {
            if (g[index_g] <= s[index_s]) {
                count++;
                index_g++;
                index_s++;
                continue;
            } else {
                index_s++;
                continue;
            }
        }
        return count;
    }
};
// @lc code=end

