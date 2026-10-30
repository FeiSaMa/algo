#include <vector>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> in_degree(numCourses, 0);
        for (auto& list : prerequisites) {
            int a = list[0];
            int b = list[1];
            in_degree[a]++;
            g[b].push_back(a);
            // 前置 -> 课
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (in_degree[i] == 0) q.push(i);
        }
        
        int done = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            done++;
            for (int neighbor : g[cur]) {
                in_degree[neighbor]--;
                if (in_degree[neighbor] == 0) q.push(neighbor);
            }
        }

        return done == numCourses;
    }
};
// @lc code=end

