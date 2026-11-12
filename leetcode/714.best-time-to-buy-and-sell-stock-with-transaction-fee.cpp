#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n == 0) return 0;
        // dp[i][0] 当天交易结束后，空仓
        // dp[i][1] 当天交易结束后，持仓
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0] - fee;
        for (int i = 1; i < n; i++) {
            int cur = prices[i];
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + cur);
            dp[i][1] = max(dp[i - 1][0] - cur - fee, dp[i - 1][1]);
        }
        return dp[n - 1][0];
    }
};
// @lc code=end

