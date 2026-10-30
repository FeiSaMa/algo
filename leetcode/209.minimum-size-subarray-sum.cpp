#include <vector>
#include <climits>

using std::vector;
/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0;
        int end = 0;
        int sum = 0;
        int minLenth = INT_MAX;
        for (end; end < nums.size(); end++) {
            sum += nums[end];
            while (sum >= target) {
                minLenth = minLenth < (end - start + 1) ? minLenth : (end - start + 1);
                sum -= nums[start];
                start++;
            }
        }
        return minLenth == INT_MAX ? 0 : minLenth;
        
    }
};
// @lc code=end

