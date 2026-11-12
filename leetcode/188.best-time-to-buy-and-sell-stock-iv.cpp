#include <vector>
#include <climits>
using namespace std;
/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        // dp[i][j][k] 第 i 天结束后的最大收益
        // dp[i][*][*] 天
        // dp[*][j][*] 是否持仓 0 / 1
        // dp[*][*][k] 做了多少笔交易 0 / 1 ... / k
        if (k >= n / 2) {
            int ans = 0;
            for (int i = 1; i < n; i++) {
                ans += max(0, prices[i] - prices[i - 1]);
            }
            return ans;
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1)));
        
        for (int i = 0; i <= 1; i++) {
            for (int j = 0; j <= k; j++) {
                if (i == 0 && j == 0) dp[0][i][j] = 0;
                else if (i == 1 && j == 1) dp[0][i][j] = -prices[0];
                else dp[0][i][j] = INT_MIN / 2;
            }
        }

        for (int i = 1; i < n; i++) {
            dp[i][0][0] = 0;
            dp[i][1][0] = INT_MIN / 2;
            for (int x = 1; x <= k; x++) {
                dp[i][0][x] = max(dp[i - 1][0][x], dp[i - 1][1][x] + prices[i]);
                dp[i][1][x] = max(dp[i - 1][1][x], dp[i - 1][0][x - 1] - prices[i]);
            }
        }
        
        int ans = INT_MIN;
        for (int x : dp[n - 1][0]) {
            ans = max(ans, x);
        }
        
        return ans;
    }
};
// @lc code=end

