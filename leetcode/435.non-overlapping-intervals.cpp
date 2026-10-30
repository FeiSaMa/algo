#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });
        int count = 0;
        int lastEnd = INT_MIN;
        for (auto& itv : intervals) {
            if (itv[0] >= lastEnd) {
                count++;
                lastEnd = itv[1];
            }
        }
        
        return (int) intervals.size() - count;
    }
};
// @lc code=end

