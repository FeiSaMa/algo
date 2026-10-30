#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // 暴力：
        int n = cost.size();
        vector<int> dp(n + 1, 0); // 走到第n格的最小cost,走到第0格初始化为cost = 0
        dp[1] = 0;
        for (int i = 2; i <= n; i++)  {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[n]; // 可优化到o(1)空间：只需pre2/pre1
    }
};
// @lc code=end

