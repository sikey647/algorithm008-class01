/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */

// @lc code=start
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   private:
    vector<vector<string> > res;
    unordered_set<string> _set;
    unordered_set<string> visited;
    queue<vector<string> > _queue;
    int level = 1;
    int minLevel = INT16_MAX;

   public:
    vector<vector<string> > findLadders(string beginWord, string endWord,
                                        vector<string> &wordList) {
        for (auto word : wordList) _set.insert(word);

        _queue.push({beginWord});

        while (!_queue.empty()) {
            vector<string> path = _queue.front();
            _queue.pop();

            if (path.size() > level) {
                for (string s : visited) _set.erase(s);
                visited.clear();
                if (path.size() > minLevel)
                    break;
                else
                    level = path.size();
            }

            string last = path.back();

            _findNextWord(last, path, endWord);
        }

        return res;
    }

    void _findNextWord(string str, vector<string> path, const string &endWord) {
        for (int i = 0; i < str.size(); i++) {
            char c = str[i];

            for (int j = 0; j < 26; j++) {
                str[i] = 'a' + j;

                if (_set.count(str)) {
                    vector<string> newPath = path;
                    newPath.push_back(str);

                    visited.insert(str);

                    if (str == endWord) {
                        minLevel = level;
                        res.push_back(newPath);
                    } else {
                        _queue.push(newPath);
                    }
                }
            }

            str[i] = c;
        }
    }
};
// @lc code=end
