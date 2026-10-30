#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = (int) height.size();
        int left = 0;
        int right = n - 1;
        int best = 0;
        while (left < right) {
            int length = right - left;
            int area = min(height[left], height[right]) * length;
            best = max(area, best);
            if (height[left] >= height[right]) {
                right--;
            } else {
                left++;
            }
        }
        
        return best;
    }
};
// @lc code=end

