#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
 * 复习题 1：和为 K 的子数组（560）
 *
 * 给定整数数组 nums 和整数 k，返回「和恰好为 k」的连续子数组的个数。
 *
 * 示例：
 *   nums = [1,1,1], k = 2  ->  2
 *   nums = [1,2,3], k = 3  ->  2
 *
 * 约束：
 *   - 可能有负数
 *   - 泄露数用 long long 存
 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // TODO: 你写
        int count = 0;
        long long cur = 0;
        unordered_map<long long, int> mp;
        mp[0] = 1;
        for (int x : nums) {
            cur += x;
            if (mp.count(cur - k)) count += mp[cur - k];
            mp[cur]++;
        }
        
        return count;
    }
};
