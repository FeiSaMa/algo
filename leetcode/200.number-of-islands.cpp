#include <vector>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = (int) grid.size();
        int n = (int) grid.front().size();
        
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    // 将整个岛屿弄沉
                    dfs(grid, i, j, m, n);
                }
            }
        }

        return count;
    }
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n) return;
        if (grid[i][j] == '0') return;

        grid[i][j] = '0';
        cout << "访问 (" << i << "," << j << ")\n";

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        dfs(grid, i + dx[0], j + dy[0], m, n);
        dfs(grid, i + dx[1], j + dy[1], m, n);
        dfs(grid, i + dx[2], j + dy[2], m, n);
        dfs(grid, i + dx[3], j + dy[3], m, n);
    }
};
// @lc code=end

