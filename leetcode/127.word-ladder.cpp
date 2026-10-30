#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;

        unordered_map<string, vector<string>> patternMap;
        for (string& word : wordList) {
            for (int i = 0; i < (int) word.size(); i++) {
                string p = word;
                p[i] = '*';
                patternMap[p].push_back(word);
            }
        }

        queue<string> q;
        q.push(beginWord);

        int count = 1;
        unordered_set<string> visited;
        visited.insert(beginWord);
        while (!q.empty()) {
            int sz = (int) q.size();
            for (int i = 0; i < sz; i++) {
                string cur = q.front(); q.pop();
                if (cur == endWord) return count;

                for (int k = 0; k < (int) cur.size(); k++) {
                    string p = cur;
                    p[k] = '*';
                    for (string nextWord : patternMap[p]) {
                        if (visited.count(nextWord)) continue;
                        q.push(nextWord);
                        visited.insert(nextWord);
                    }
                    patternMap[p].clear();
                }

            }
            count++;
        }

        return 0;
    }
};
// @lc code=end

