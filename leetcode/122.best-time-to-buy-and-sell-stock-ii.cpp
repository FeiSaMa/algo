#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        // dp[i][0] 当天交易结束后，未持有股票的最大收益
        // dp[i][1] 当天交易结束后，持有股票的最大收益
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            int cur = prices[i];
            dp[i][0] = max(dp[i - 1][1] + cur, dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - cur);
        }
        return dp[n - 1][0];
    }
};
// @lc code=end

