#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> used(nums.size(), false);
        vector<int>path;
        dfs(nums, used, path, ans);
        return ans;
    }
    
    void dfs(vector<int>& nums, vector<bool>& used, vector<int>& path, vector<vector<int>>& ans) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            used[i] = true;
            path.push_back(nums[i]);
            dfs(nums, used, path, ans);
            path.pop_back();
            used[i] = false;
        }
    }
};
// @lc code=end

