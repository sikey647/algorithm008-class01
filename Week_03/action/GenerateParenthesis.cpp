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
        _generateParenthesis(0, 0, n, "", res);
        return res;
    }

    void _generateParenthesis(int left, int right, int n, string s,
                              vector<string>& res) {
        if (left == n && right == n) {
            res.push_back(s);
            return;
        }

        if (left < n) _generateParenthesis(left + 1, right, n, s + "(", res);

        if (left > right)
            _generateParenthesis(left, right + 1, n, s + ")", res);
    }
    // vector<string> generateParenthesis(int n) {
    //     vector<string> res;
    //     _generateParenthesis(0, n * 2, "", res);
    //     return res;
    // }

    // void _generateParenthesis(int k, int maxLevel, string s,
    //                           vector<string>& res) {
    //     if (k == maxLevel) {
    //         res.push_back(s);
    //         return;
    //     }

    //     _generateParenthesis(k + 1, maxLevel, s + "(", res);
    //     _generateParenthesis(k + 1, maxLevel, s + ")", res);
    // }
};
// @lc code=end
