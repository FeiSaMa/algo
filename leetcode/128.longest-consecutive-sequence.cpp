#include <vector>
#include <unordered_set>
using std::vector, std::unordered_set;
/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int best = 0;
        for (int x : st) {
            if (!st.count(x - 1)) {
                int count = 1;
                int head = x;
                while (st.count(head + 1)) {
                    count++;
                    head++;
                }
                best = std::max(best, count);
            }
        }
        return best;
    }
};
// @lc code=end

