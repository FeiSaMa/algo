#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

// @lc code=start
// class NumMatrix {
// private:
//     vector<int> line_matrix;
//     vector<long long> pre;
//     int n;
//     int num;
// public:
//     NumMatrix(vector<vector<int>>& matrix){
//         int n_r = matrix.size();
//         int n_c = matrix[0].size();
//         for (int i = 0; i < n_r; i++) {
//             for (int j = 0; j < n_c; j++) {
//                 line_matrix.push_back(matrix[i][j]);
//             }
//         }
//         n = n_c;
//         num = n_r * n_c;
        
//         pre.assign(num + 1, 0);
//         pre[0] = 0;
//         for (int i = 1; i <= line_matrix.size(); i++) {
//             pre[i] = pre[i - 1] + line_matrix[i - 1];
//         }
//     }
//     int sumRegion(int row1, int col1, int row2, int col2) {

//         int cur{};
//         int delta_row = row2 - row1 + 1;
//         // delta_row 表示要算几次
//         for (int i = 0; i < delta_row; i++) {
//             int start_index = (row1 + i) * n + col1;
//             int end_index = (row1 + i) * n + col2;
//             cur += pre[end_index + 1] - pre[start_index];
//         }

//         return cur;
//     }
// };
class NumMatrix {
    vector<vector<long long>> pre;
public:
    NumMatrix(vector<vector<int>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();

        pre.assign(m + 1, vector<long long>(n + 1, 0));
        
        // pre[i][j] -> (0, 0)到(i - 1, j - 1)的和
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return pre[row2 + 1][col2 + 1] - pre[row1][col2 + 1] - pre[row2 + 1][col1] + pre[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

