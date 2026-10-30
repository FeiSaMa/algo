#include <climits>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // // dp[i] 为以第i个元素结尾的最大和
        // vector<int> dp(nums.size());
        // dp[0] = nums[0];
        // int best = dp[0];
        // for (int i = 1; i < nums.size(); i++) {
        //     dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        //     best = dp[i] > best ? dp[i] : best;
        // }
        // return best;
        // 只需要前一个的值，做空间优化
        int dp_pre = nums[0];
        int best = dp_pre;
        for (int i = 1; i < nums.size(); i++) {
            int cur = max(dp_pre + nums[i], nums[i]);
            dp_pre = cur; // 推进dp_pre
            best = cur > best ? cur : best;
        }
        return best;
    }
};
// @lc code=end

