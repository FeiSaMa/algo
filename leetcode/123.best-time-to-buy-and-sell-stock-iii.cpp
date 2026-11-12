#include <vector>
#include <climits>
using namespace std;
/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        // dp[i][j][k] 代表第 i 天结束后的最大收益
        // dp[i] -> 天数
        // dp[j] -> 手上是否有货物
        // dp[k] -> 用了几笔交易，只在买入的时候计数
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3)));
        dp[0][0][0] = 0;
        dp[0][1][1] = -prices[0];
        dp[0][1][0] = INT_MIN / 2;
        dp[0][0][1] = INT_MIN / 2;
        dp[0][0][2] = INT_MIN / 2;
        dp[0][1][2] = INT_MIN / 2;
        for (int i = 1; i < n; i++) {
            dp[i][0][0] = 0;
            dp[i][1][0] = INT_MIN / 2;
            for (int k = 1; k <= 2; k++) {
                dp[i][0][k] = max(dp[i - 1][0][k], dp[i - 1][1][k] + prices[i]);
                dp[i][1][k] = max(dp[i - 1][1][k], dp[i - 1][0][k - 1] - prices[i]);
            }
        }
        
        int ans = INT_MIN;
        for (int x : dp[n - 1][0]) {
            if (x > ans) ans = x;
        }
        return ans;
    }
};
// @lc code=end

