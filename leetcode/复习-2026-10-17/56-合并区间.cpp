#include <vector>
#include <algorithm>
using namespace std;

/*
 * 复习题 3：合并区间（56）
 *
 * 给定一个区间集合 intervals，合并所有重叠的区间，返回互不重叠的区间数组。
 *
 * 示例：
 *   intervals = [[1,3],[2,6],[8,10],[15,18]]  ->  [[1,6],[8,10],[15,18]]
 *   intervals = [[1,4],[4,5]]                 ->  [[1,5]]
 *
 * 约束：
 *   - 端点相接（如 [1,4] 和 [4,5]）视为重叠，需要合并
 *   - 返回值是 vector<vector<int>>
 */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // TODO: 你写
        vector<vector<int>> ans;
        
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[0] < b[0];
        });

        
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
