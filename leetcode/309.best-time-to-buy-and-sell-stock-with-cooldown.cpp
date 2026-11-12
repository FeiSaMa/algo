#include <climits>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        // dp[i][0] 第 i 天结束后，空仓并且下一天能买
        // dp[i][1] 第 i 天结束后，持仓
        // dp[i][2] 第 i 天结束后，空仓并且下一天不能买（当天卖了）
        vector<vector<int>> dp(n, vector<int>(3));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = INT_MIN / 2;
        for (int i = 1; i < n; i++) {
            int cur = prices[i];

            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - cur);
            dp[i][2] = dp[i - 1][1] + cur;
        }
        return max(dp[n - 1][0], dp[n - 1][2]);
    }
};
// @lc code=end

