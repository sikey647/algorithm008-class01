/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n <= 0) return res;

        dfs(0, 0, n, "", res);

        return res;
    }

    void dfs(int left, int right, int n, string s, vector<string> &res) {
        if (s.size() == 2 * n) {
            res.push_back(s);
            return;
        }

        if (left < n) dfs(left + 1, right, n, s + "(", res);
        if (right < left) dfs(left, right + 1, n, s + ")", res);
    }
};
// @lc code=end
