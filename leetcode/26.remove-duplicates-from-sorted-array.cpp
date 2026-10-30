#include <vector>
/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[k]) {
                nums[k + 1] = nums[i];
                k++;
            }
        }
        return k + 1;
    }
};
// @lc code=end

