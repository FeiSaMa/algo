#include <vector>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start
class Solution {
private:
    int m, n;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = (int) mat.size();
        n = (int) mat.front().size();
        vector<vector<int>> dist(m, vector<int>(n, -1)); // -1 表示未访问
        
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j]++; // -1 -> 0
                }
            }
        }
        
        while (!q.empty()) {
            auto[i, j] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if (dist[ni][nj] != -1) continue;
                dist[ni][nj] = dist[i][j] + 1;
                q.push({ni, nj});
            }
        }

        return dist;
    }
};
// @lc code=end

