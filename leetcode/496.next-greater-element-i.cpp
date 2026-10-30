#include <vector>
#include <stack>
#include <unordered_map>
using std::vector, std::stack, std::unordered_map;
/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        stack<int> st;
        vector<int> ans;
        unordered_map<int, int> mp;
        for (int i = 0; i < (int) nums2.size(); i++) {
            while (!st.empty() && nums2[st.top()] < nums2[i]) {
                int j = st.top();
                st.pop();
                mp[nums2[j]] = nums2[i];
            }
            st.push(i);
        }
        
        for (int j = 0; j < n; j++) {
            if (mp.count(nums1[j])) ans.push_back(mp[nums1[j]]);
            else ans.push_back(-1);
        }

        return ans;
    }
};
// @lc code=end

