#include <vector>
using std::vector;
/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */

// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // fixed sliding window
        double average{};
        for (int i = 0; i < k; i++) {
            average += 1.0 * nums[i] / k;
        }
        int start{};
        double maxAverage = average;
        for (int end = k; end < nums.size(); end++) {
            average += 1.0 * nums[end] / k;
            average -= 1.0 * nums[start] / k;
            start++;
            maxAverage = average >= maxAverage ? average : maxAverage; 
        }
        return maxAverage;
    }
};
// @lc code=end

