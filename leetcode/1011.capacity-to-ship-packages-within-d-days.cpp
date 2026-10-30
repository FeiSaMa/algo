#include <vector>
#include <climits>
using namespace std;
/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int minCap = findMax(weights);
        int maxCap = getSum(weights);

        int targetCap = findMinCap(weights, days, minCap, maxCap);
        return targetCap;
    }

    int findMinCap(vector<int>& weights, int days, int minCap, int maxCap) {
        int left = minCap;
        int right = maxCap;
        while (left < right) {
            int mid = left + (right - left) / 2; // mid >= left
            if (canFinish(mid, weights, days)) right = mid;
            else left = mid + 1;
        }
        return left;
    }

    bool canFinish(int capacity, vector<int>& weights, int days) {
        int daysNeeded = 1;
        long long cur{};
        for (int w : weights) {
            if (w + cur > capacity) {
                daysNeeded++;
                cur = w;
            }
            else cur += w;
        }
        return daysNeeded <= days;
    }

    long long getSum(vector<int>& weights) {
        long long cur{};
        for (int x : weights) {
            cur += x;
        }
        return cur;
    }

    int findMax(vector<int>& weights) {
        int best = 0;
        for (int x : weights) best = max(best, x);
        return best;
    }
};
// @lc code=end

