#include <vector>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> in_degree(numCourses, 0);
        vector<int> ans;
        for (auto& list : prerequisites) {
            int a = list.front();
            int b = list.back();
            in_degree[a]++;
            g[b].push_back(a);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (in_degree[i] == 0) q.push(i);
        }
        
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            ans.push_back(cur);
            for (int x : g[cur]) {
                in_degree[x]--;
                if (in_degree[x] == 0) q.push(x);
            }
        }
        
        if ((int) ans.size() == numCourses) return ans;
        else return {};
    }
};
// @lc code=end

