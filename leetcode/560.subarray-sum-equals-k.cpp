#include <vector>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long, int> mp;
        mp[0] = 1;
        long long cur{};
        int ans{};
        for (int x : nums) {
            cur += x;
            if (mp.count(cur - k)) ans += mp[cur - k];
            mp[cur]++;
        }
        
        return ans;
    }
};
// @lc code=end

