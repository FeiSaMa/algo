#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int first = lowerBound(nums, target);
        int last = upperBound(nums, target);
        
        if (first == n || nums[first] != target) return {-1, -1};
        return {first, last - 1};
    }
    
    int lowerBound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) right = mid;
            else left = mid + 1;
        }
        return left;
    }
    
    int upperBound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
// @lc code=end

