#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](auto& a, auto& b) {
            return a[0] < b[0];
        });
        vector<vector<int>> merged_itvs;
        for (auto itv : points) {
            if (!merged_itvs.empty() && merged_itvs.back()[1] >= itv[0]) {
                merged_itvs.back()[0] = max(merged_itvs.back()[0], itv[0]);
                merged_itvs.back()[1] = min(merged_itvs.back()[1], itv[1]);
                continue;
            }
            merged_itvs.push_back(itv);
        }

        return merged_itvs.size();
    }
};
// @lc code=end

