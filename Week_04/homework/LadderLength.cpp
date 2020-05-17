/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    int ladderLength(string beginWord, string endWord,
                     vector<string> &wordList) {
        set<string> _set(wordList.begin(), wordList.end());
        if (!_set.count(endWord)) return 0;

        int len = 1;
        queue<string> _queue;
        _queue.push(beginWord);
        _set.erase(beginWord);

        while (!_queue.empty()) {
            int size = _queue.size();
            for (int i = 0; i < size; i++) {
                string s = _queue.front();
                _queue.pop();

                if (s == endWord) return len;

                _findNextWorld(s, _queue, _set);
            }
            len++;
        }

        return 0;
    }

    void _findNextWorld(string s, queue<string> &_queue, set<string> &_set) {
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            for (int j = 0; j < 26; j++) {
                s[i] = 'a' + j;
                if (_set.count(s)) {
                    _queue.push(s);
                    _set.erase(s);
                }
            }
            s[i] = c;
        }
    }
};
// @lc code=end
