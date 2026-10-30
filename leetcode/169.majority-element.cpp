#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;
/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        int best = INT_MIN;
        int best_element;
        for (int x : nums) {
            mp[x]++;
            if (mp[x] > best) {
                best = mp[x];
                best_element = x; 
            }
        }
        return best_element;
    }
};
// @lc code=end

