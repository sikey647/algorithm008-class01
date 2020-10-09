/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

#include <vector>
using namespace std;

// ?????????
// @lc code=start
class Solution {
   public:
    // 1?????????
    // int climbStairs(int n) {
    //     if (n == 1 || n == 2) return n;

    //     return climbStairs(n - 1) + climbStairs(n - 2);
    // }

    // 2????? + ???
    // int climbStairs(int n) {
    //     vector<int> v(n + 1);
    //     return _climbStairs(n, v);
    // }

    // int _climbStairs(int n, vector<int> &v) {
    //     if (n == 1 || n == 2) return n;

    //     if (v[n] == 0) v[n] = _climbStairs(n - 1, v) + _climbStairs(n - 2,
    //     v);

    //     return v[n];
    // }

    // 3???????????
    int climbStairs(int n) {
        if (n == 1 || n == 2) return n;

        int f1 = 1, f2 = 2, f3 = 0;
        for (int i = 3; i <= n; i++) {
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }

        return f3;
    }
};
// @lc code=end
