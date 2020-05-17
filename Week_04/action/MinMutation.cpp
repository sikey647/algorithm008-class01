/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 */

// @lc code=start
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    int minMutation(string start, string end, vector<string> &bank) {
        set<string> _set(bank.begin(), bank.end());
        if (!_set.count(end)) return -1;
        int step = 0;
        queue<string> _queue;
        _queue.push(start);
        _set.erase(start);

        while (!_queue.empty()) {
            int size = _queue.size();
            for (int i = 0; i < size; i++) {
                string s = _queue.front();
                _queue.pop();

                if (s == end) return step;

                _findNextStr(s, _queue, _set);
            }

            step++;
        }

        return -1;
    }

    void _findNextStr(string s, queue<string> &_queue, set<string> &_set) {
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            for (char e : string("ACGT")) {
                s[i] = e;
                if (_set.count(s)) {
                    _queue.push(s);
                    _set.erase(s);
                }
                s[i] = c;
            }
        }
    }
};
// @lc code=end
