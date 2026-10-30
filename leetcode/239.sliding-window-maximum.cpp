#include <vector>
#include <deque>
using std::vector,
      std::deque;
/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> maxNums;
        for (int end = 0; end < (int)nums.size(); end++) {
            while (!dq.empty() && nums[dq.back()] <= nums[end]) {
                dq.pop_back();
            }
            dq.push_back(end);
            while (!dq.empty() && dq.front() < end - k + 1) {
                dq.pop_front();
            }
            if (end >= k - 1) maxNums.push_back(nums[dq.front()]);
        }
        return maxNums;
    }
};
// @lc code=end

