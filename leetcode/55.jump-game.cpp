#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach {};
        for (size_t i = 0; i < nums.size(); i++) {
            int cnt = i + nums[i];
            if (i <= reach) reach = max(reach, cnt);
            if (reach >= (int) nums.size() - 1) return true;
        }
        return false;
    }
};
// @lc code=end

