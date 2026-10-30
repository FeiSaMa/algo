#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = (int) isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(isConnected, visited, i);
            }
        }
        return count;
    } 

    void dfs(vector<vector<int>>& g, vector<bool>& visited, int u) {
        visited[u] = true;
        int n = (int) g.size();
        for (int j = 0; j < n; j++) {
            if (g[u][j] == 1 && !visited[j]) {
                visited[j] = true;
                dfs(g, visited, j);
            }
        }
        // vector<int> neighbor = g[u];
        // for (int j = 0; j < n; j++) {
        //     if (neighbor[j] == 1 && !visited[j]) {
        //         visited[j] = true;
        //         dfs(g, visited, j);
        //     }
        // }
    }
};
// @lc code=end

