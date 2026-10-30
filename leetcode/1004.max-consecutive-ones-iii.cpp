#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start{};
        int zeroCount{};
        int best{};
        for (int end = 0; end < (int)nums.size(); end++) {
            if (nums[end] == 0) zeroCount++;
            while (zeroCount > k) {
                if (nums[start] == 0) zeroCount--;
                start++;
            }
            best = (end - start + 1) > best ? (end - start + 1) : best;
        }
        return best;
    }
};
// @lc code=en

