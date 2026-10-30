#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        // dp[i][j] -> word1的前 i 个字符变成word2的前 j 个字符需要多少步
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int i = 0; i <= n; i++) dp[0][i] = i;

        for (int k = 1; k <= m; k++) {
            for (int j = 1; j <= n; j++) {
                if (word1[k - 1] == word2[j - 1]) dp[k][j] = dp[k - 1][j - 1];
                else {
                    dp[k][j] = min({dp[k][j - 1],
                                   dp[k - 1][j],
                                   dp[k - 1][j - 1]}) + 1;
                }
            }
        }

        return dp[m][n];
    }
};
// @lc code=end

