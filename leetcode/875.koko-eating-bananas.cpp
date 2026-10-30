#include <vector>
#include <climits>
using namespace std;
/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int k_min = 1;
        int k_max = findMax(piles);
        
        int minSpeed = getMinSpeed(piles, h, k_min, k_max);
        return minSpeed;
    }

    int findMax(vector<int>& array) {
        int maxElement = INT_MIN;
        for (int x : array) maxElement = max(x, maxElement);
        return maxElement;
    }
    
    bool canFinish(vector<int>& piles, int h, int k) {
        long long time{};
        for (int x : piles) {
            // 向上取整
            time += ((long long)x + k - 1) / k;
        }
        if (time > h) return false;
        else return true;
    }

    int getMinSpeed(vector<int>& piles, int h, int minSpeed, int maxSpeed) {
        int left = minSpeed;
        int right = maxSpeed;
        while (left < right) {
            int mid = left + (right - left) / 2; // mid >= left
            if (canFinish(piles, h, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
// @lc code=end

