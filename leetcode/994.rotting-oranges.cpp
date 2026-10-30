#include <vector>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = (int) grid.size();
        int n = (int) grid.front().size();
        
        queue<pair<int, int>> q;
        int fresh = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) fresh++;
            }
        }
        
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        
        int minutes = 0;
        while (!q.empty()) {
            int sz = (int) q.size();
            bool isSpread = false;
            for (int k = 0; k < sz; k++) {
                auto[i, j] = q.front();
                q.pop();
                for (int x = 0; x < 4; x++) {
                    int next_i = i + dx[x];
                    int next_j = j + dy[x];
                    if (next_i < 0 || next_i >= m || next_j < 0 || next_j >= n) continue;
                    if (grid[next_i][next_j] != 1) continue;
                    grid[next_i][next_j] = 2;
                    isSpread = true;
                    q.push({next_i, next_j});
                    fresh--;
                }
            }
            if (isSpread) minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};
// @lc code=end

