#include <vector>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        // value -> index
        for (int i = 0; i < (int) nums.size(); i++) {
            if (mp.count(nums[i]) && (i - mp[nums[i]]) <= k) return true;
            mp[nums[i]] = i;
        }
        return false;
    }
};
// @lc code=end

