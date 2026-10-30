#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

/*
 * 复习题：在 D 天内送达包裹的能力（1011）
 *
 * 传送带上的第 i 个包裹重量为 weights[i]。每一天，我们都会按给出重量
 * 的顺序往传送带上装载包裹。我们装载的重量不会超过船的最大运载重量。
 *
 * 返回能在 days 天内将传送带上所有包裹送达的船的最低运载能力。
 *
 * 示例：
 *   weights = [1,2,3,4,5,6,7,8,9,10], days = 5  ->  15
 *   weights = [3,2,2,4,1,4],          days = 3  ->  6
 *   weights = [1,2,3,1,1],            days = 4  ->  3
 *
 * 约束：
 *   - 包裹必须按顺序装船（不能重排）
 *   - 船每趟只能装一天的量
 */

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // TODO: 你写
        int minCap = *max_element(weights.begin(), weights.end());
        int maxCap = accumulate(weights.begin(), weights.end(), 0);
        int ans = findMinCapacity(minCap, maxCap, days, weights);

        return ans;
    }
    
    int findMinCapacity(int minCap, int maxCap, int days, vector<int>& weight) {
        // 在minCap与maxCap之间找到最小的Cap
        int left = minCap;
        int right = maxCap;
        // 二分
        while (left < right) {
            int mid = left + (right - left) / 2; // mid >= left
            if (can(mid, days, weight)) right = mid;
            else left = mid + 1;
        }
        
        return left;
    }

    bool can(int capacity, int days, vector<int>& weight) {
        // 判断capacity的船能否在days天内将所有包裹送达  
        long long cur = 0;
        int k = 1;
        for (int x : weight) {
            cur += x;
            if (cur > capacity) {
                cur = x;
                k++;
            }
        }
        return k <= days;
    }
};
