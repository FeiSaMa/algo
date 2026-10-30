#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

/*
 * 复习题：每日温度（739）
 *
 * 给定一个整数数组 temperatures，表示每天的温度。
 * 返回一个数组 answer，其中 answer[i] 是指对于第 i 天，
 * 下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。
 *
 * 示例：
 *   temperatures = [73,74,75,71,69,72,76,73]  ->  [1,1,4,2,1,1,0,0]
 *   temperatures = [30,40,50,60]              ->  [1,1,1,0]
 *   temperatures = [30,60,90]                 ->  [1,1,0]
 *
 * 约束：
 *   - 返回的是「距离」（几天后），不是温度值
 *   - 找不到返回 0
 */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // TODO: 你写
        int length = (int) temperatures.size();
        vector<int> ans(length, 0);
        stack<int> st;

        for (int i = 0; i < (int) temperatures.size(); i++) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                int j = st.top();
                ans[j] = i - j;
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};
