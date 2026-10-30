#include <vector>
#include <cmath>
using namespace std;
/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int n = nums.size();
        vector<int> ans(n, 0);
        while (left <= right) {
            if (abs(nums[left]) >= abs(nums[right])) {
                ans[n - 1] = nums[left] * nums[left];
                left++;
            } else {
                ans[n - 1] = nums[right] * nums[right];
                right--;
            }
            n--;
        }
        return ans;
    }
};
// @lc code=end

