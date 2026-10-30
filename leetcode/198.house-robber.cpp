#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int dp_pre1 = 0; // 前 i - 2间最优
        int dp_pre2 = nums.front(); // 前 i - 1间最优
        for (int i = 2; i <= nums.size(); i++) {
            int cur = max(dp_pre2, dp_pre1 + nums[i - 1]);
            dp_pre1 = dp_pre2;
            dp_pre2 = cur;
        }
        return dp_pre2;
    }
};
// @lc code=end

