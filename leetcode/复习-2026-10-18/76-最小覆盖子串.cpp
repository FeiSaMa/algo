#include <vector>
#include <string>
#include <climits>
using namespace std;

/*
 * 复习题：最小覆盖子串（76）★ Hard
 *
 * 给定两个字符串 s 和 t，返回 s 中涵盖 t 所有字符的最小子串。
 * 如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 ""。
 *
 * 示例：
 *   s = "ADOBECODEBANC", t = "ABC"  ->  "BANC"
 *   s = "a",             t = "a"    ->  "a"
 *   s = "a",             t = "aa"   ->  ""
 *
 * 约束：
 *   - t 里可能有重复字符（要覆盖的是「每种字符的出现次数」）
 *   - 答案保证唯一
 *   - 只含大小写英文字母
 */

class Solution {
public:
    string minWindow(string s, string t) {
        // TODO: 你写
        int sizeS = (int) s.size();
        int sizeT = (int) t.size();
        if (sizeS < sizeT) return "";

        int cntT[128] {0};
        for (char c : t) {
            cntT[c]++;
        }
        
        int cntS[128] {0};
        int left = 0;
        int best = INT_MAX;
        
        int best_left = 0;

        for (int right = 0; right < sizeS; right++) {
            // update window
            cntS[s[right]]++;

            while (isMatched(cntS, cntT, 128)) {
                int length_window = right - left + 1;
                if (best > length_window) {
                    best = length_window;
                    best_left = left;
                }
                cntS[s[left]]--;
                left++;
            }
            

        }
        if (best == INT_MAX) return "";
        return s.substr(best_left, best);

    }

    bool isMatched(int* arr1, int* arr2, int length) {
        for (int i = 0; i < length; i++) {
            if (arr1[i] < arr2[i]) return false;
        }
        return true;
    }
};
