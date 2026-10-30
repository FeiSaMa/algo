#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start
class NumArray {
private:
    vector<long long> pre;
public:
    NumArray(vector<int>& nums) {
        pre.assign(nums.size() + 1, 0);
        for (int i = 1; i <= (int)nums.size(); i++) {
            pre[i] = pre[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        return pre[right + 1] - pre[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

