#include <string>
#include <vector>
using std::string,
      std::vector;
/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        string index = "MDCLXVI";
        vector<int> nums = {1000, 500, 100, 50, 10, 5, 1};
        vector<int> sort;
        for (char x : s) {
            for (int i = 0; i < 7; i++) {
                if (x == index[i]) {
                    sort.push_back(i);
                }
            }
        }

        int sum = 0;
        for (int j = 0; j < sort.size(); j++) {     
            if (j == sort.size() - 1) {
                sum += nums[sort[j]];
                break;
            }
            if (sort[j] <= sort[j + 1]) {
                sum += nums[sort[j]];
            }
            else {
                sum += nums[sort[j + 1]] - nums[sort[j]];
                j++;
            }
        }
        
        return sum;

    }
};
// @lc code=end

