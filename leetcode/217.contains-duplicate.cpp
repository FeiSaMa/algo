#include <vector>
#include <unordered_set>
using namespace std;
/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        st.reserve(nums.size());
        for (int i = 0; i < (int) nums.size(); i++) {
            if (!st.insert(nums[i]).second) return true;
        }
        return false;
    }
};
// @lc code=end

