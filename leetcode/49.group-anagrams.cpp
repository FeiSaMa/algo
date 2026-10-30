#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp; 
        for (int i = 0; i < (int) strs.size(); i++) {
            int cnt[26] {};
            // count for each string
            for (int k = 0; k < (int) strs[i].size(); k++) {
                cnt[strs[i][k] - 'a']++;
            }
            // cnt array to coded string
            string code;
            for (int j = 0; j < 26; j++) {
                code += (to_string(cnt[j]) + '*');
            }

            mp[code].push_back(strs[i]);
        }
        for (auto& [k, v] : mp) ans.push_back(v);
        return ans;
    }
};
// @lc code=end

