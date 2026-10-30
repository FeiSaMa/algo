#include <vector>
#include <algorithm>
using namespace std;

/*
 * 复习题 2：三数之和（15）
 *
 * 给定整数数组 nums，找出所有「和为 0」的三元组 [a, b, c]。
 * 要求：答案中不能包含重复的三元组。
 *
 * 示例：
 *   nums = [-1,0,1,2,-1,-4]  ->  [[-1,-1,2], [-1,0,1]]
 *   nums = [0,1,1]           ->  []
 *   nums = [0,0,0]           ->  [[0,0,0]]
 *
 * 约束：
 *   - 三元组的值相同即视为重复（下标不同也算重复）
 *   - 返回值是 vector<vector<int>>，存的是值不是下标
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // TODO: 你写
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        int n = (int) nums.size();
        for (int i = 0; i < n - 2; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            if (nums[i] > 0) break;

            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > 0) right--;
                else if (sum < 0) left++;
                else {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                }
            }
        }
        
        return ans;
    }
};
