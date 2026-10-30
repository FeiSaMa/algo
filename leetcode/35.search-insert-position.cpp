#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2; // mid >= left
            if (nums[mid] >= target) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
// @lc code=end

