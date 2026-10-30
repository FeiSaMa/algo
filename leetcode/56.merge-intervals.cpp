#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[0] < b[0];
        });
        vector<vector<int>> ans; 

        for (auto& itv : intervals) {
            if (!ans.empty() && itv[0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], itv[1]);
            } else {
                ans.push_back(itv);
            }
        }

        return ans;
    }
};
// @lc code=end

