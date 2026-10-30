#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

// @lc code=start
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = (int) rooms.size();
        vector<bool> visited(n, false);
        dfs(rooms, visited, 0);

        for (bool isVisited : visited) {
            if (!isVisited) return false;
        }
        return true;
    }
    
    void dfs(vector<vector<int>>& g, vector<bool>& visited, int i) {
        visited[i] = true;
        for (int key : g[i]) {
            if (!visited[key]) {
                dfs(g, visited, key);
            }
        }
    }
};
// @lc code=end

