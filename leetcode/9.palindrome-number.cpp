/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x < 0) {
            return false;
        }
        
        vector<int> nums;
        while (x >= 1) {
            nums.push_back(x % 10);
            x = x / 10;
        }

        for (int i = 0; i < nums.size() / 2; i++) {
            if (nums[i] != nums[nums.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

