#include <climits>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[amount] = 凑出amount需要的最少硬币数量
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            int best = INT_MAX;
            for (int x : coins) {
                if (i - x >= 0 && dp[i - x] != -1) {
                    best = min(best, dp[i - x]);
                }
                if (best != INT_MAX) dp[i] = best + 1;
            }
        }
        return dp[amount];
    }
};
// @lc code=end

