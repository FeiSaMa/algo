#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int x : nums) sum += x;
        
        if (sum % 2 != 0) return false;
        int target = sum / 2;

        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int x : nums) {
            for (int i = target; i >= x; i--) {
                dp[i] = dp[i] || dp[i - x];
            }
        }

        return dp[target];
    }
};
// @lc code=end

