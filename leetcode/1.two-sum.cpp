#include <vector>
#include <unordered_map>
using std::vector,
      std::unordered_map;
/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (int i = 0; i < (int) nums.size(); i++) {
            if (mp.count(target - nums[i])) {
                return {i, mp[target - nums[i]]};
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};
// @lc code=end

