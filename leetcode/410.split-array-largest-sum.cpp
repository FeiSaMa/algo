#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */

// @lc code=start
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int minL = *max_element(nums.begin(), nums.end());
        int maxL = accumulate(nums.begin(), nums.end(), 0);
        
        int minSum = findMin(nums, k, minL, maxL);
        return minSum;
    }

    bool can(vector<int>& nums, int k, int l) {
        int cnt{};
        int num = 1;
        for (int x : nums) {
            if (cnt + x > l) {
                cnt = x;
                num++;
            }
            else {
                cnt += x;
            }
        }
        
        return num <= k;
    }
    
    int findMin(vector<int>& nums, int k, int minL, int maxL) {
        int lo = minL;
        int hi = maxL;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2; // mid >= lo
            // mid 的值越大, 越容易 <= k
            if (can(nums, k, mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
    

};
// @lc code=end

