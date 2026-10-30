#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=1109 lang=cpp
 *
 * [1109] Corporate Flight Bookings
 */

// @lc code=start
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // 暴力解法
        // vector<int> ans(n, 0);
        // int n_books = bookings.size();
        // for (int i = 0; i < n_books; i++) {
        //     int index_start = bookings[i][0] - 1;
        //     int index_end = bookings[i][1] - 1;
        //     for (int j = index_start; j <= index_end; j++) ans[j] += bookings[i][2];
        // }
        // return ans;

        // 使用差分，将每一个增量记录到差分数组d
        // d[n] = arr[n] - arr[n - 1]
        vector<long long> d(n + 1, 0);
        vector<int> ans(n, 0);
        int n_books = bookings.size();

        for (int i = 0; i < n_books; i++) {
            int start_index = bookings[i][0] - 1;
            int end_index = bookings[i][1] - 1;
            int delta = bookings[i][2];
            d[start_index] += delta;
            d[end_index + 1] -= delta;
        }

        long long cur{};
        for (int i = 0; i < n; i++) {
            cur += d[i];
            ans[i] = cur;
        }
        
        return ans;
    }
};
// @lc code=end

