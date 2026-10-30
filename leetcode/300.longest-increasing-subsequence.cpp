#include <vector>
#include <climits>
using namespace std;
/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i] -> 以第i个元素结尾的最长严格单增子序列的长度
        vector<int> dp(nums.size(), 1);
        dp[0] = 1;
        int bestLength = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                // j [0, j - 1]
                // 需要满足严格单增 nums[j] < nums[i]
                if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
            if (dp[i] > bestLength) bestLength = dp[i];
        }

        return bestLength;
    }
};
// @lc code=end

