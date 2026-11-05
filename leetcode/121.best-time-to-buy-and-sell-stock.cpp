#include <vector>
#include <climits>
using namespace std;
/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int ans = 0;
        for (int price : prices) {
            minPrice = min(price, minPrice);
            ans = max(ans, price - minPrice);
        }
        return ans;
    }
};
// @lc code=end

