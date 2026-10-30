#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start

/*
 * 岛屿的最大面积
 *
 * 给你一个大小为 m x n 的二进制矩阵 grid 。
 * 岛屿是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1
 * 必须在水平或者竖直的四个方向上相邻。你可以假设 grid 的四个边缘都被 0 包围着。
 * 岛屿的面积是岛上值为 1 的单元格的数目。
 *
 * 计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。
 *
 * 示例 1:
 *   输入：grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],
 *                [0,0,0,0,0,0,0,1,1,1,0,0,0],
 *                [0,1,1,0,1,0,0,0,0,0,0,0,0],
 *                [0,1,0,0,1,1,0,0,1,0,1,0,0],
 *                [0,1,0,0,1,1,0,0,1,1,1,0,0],
 *                [0,0,0,0,0,0,0,0,0,0,1,0,0],
 *                [0,0,0,0,0,0,0,1,1,1,0,0,0],
 *                [0,0,0,0,0,0,0,1,1,0,0,0,0]]
 *   输出：6
 *   解释：注意答案不应该包含倾斜方向的岛屿。
 *
 * 示例 2:
 *   输入：grid = [[0,0,0,0,0,0,0,0]]
 *   输出：0
 */

class Solution {
private:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // TODO: 你写
        int m = (int) grid.size();
        int n = (int) grid.front().size();
        
        int best = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int count = dfs(i, j, grid);
                    best = max(count, best);
                }
            }
        }
        
        return best;
    }
    int dfs(int i, int j,vector<vector<int>>& grid) {
        // return the number of area;
        int m = (int) grid.size();
        int n = (int) grid.front().size();
        if (i < 0 || i >= m || j < 0 || j >= n) return 0;
        if (grid[i][j] == 0) return 0;
        
        // 组成了递归语义成立的一部分
        grid[i][j] = 0;
        int count = 1;
        for (int x = 0; x < 4; x++) {
            count += dfs(i + dx[x], j + dy[x], grid);
        }
        return count;
    }
};
// @lc code=end
