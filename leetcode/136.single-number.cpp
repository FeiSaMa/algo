#include <vector>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp; // nums中的数字 -> 数字出现的个数
        for (int x : nums) {
            mp[x]++; 
        }

        for (auto& [i, j] : mp) {
            if (j == 1) return i;
        }

        return 0;
    }
};
// @lc code=end

