#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 */

// @lc code=start
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        const int MAX_STOP = 1001;
        int n = trips.size();
        vector<long long> d(MAX_STOP, 0);
        for (int i = 0; i < n; i++) {
            int delta = trips[i][0];
            int start_index = trips[i][1];
            int end_index = trips[i][2];
            d[start_index] += delta;
            // 正常情况下，应该是 d[end_index + 1] -= delta
            // 但是先下后上，所以有下有上的站点，是否装得下取决于上车的人数
            // 所以写成delta[index] -= delta
            // [l, r] 中 r 不用加
            d[end_index] -= delta;
        }

        long long cur{};
        for (int i = 0; i < MAX_STOP; i++) {
            cur += d[i];
            if (cur > capacity) return false;
        }
        
        return true;
    }
};
// @lc code=end

