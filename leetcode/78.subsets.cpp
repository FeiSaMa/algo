#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(0, ans, path, nums);
        return ans;
    }

    void dfs(int start, vector<vector<int>>& ans, vector<int>& path, vector<int>& nums) {
        ans.push_back(path);

        for (int i = start; i < (int)nums.size(); i++) {
            path.push_back(nums[i]);
            dfs(i + 1, ans, path, nums);
            path.pop_back();
        }
    }
};
// @lc code=end

