/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    int climbStairs(int n) {
        vector<int> v(n + 1, 0);

        return _climbStairs(v, n);
    }

    int _climbStairs(vector<int>& v, int n) {
        if (n == 1 || n == 2) return n;

        if (v[n] > 0) return v[n];

        v[n] = _climbStairs(v, n - 1) + _climbStairs(v, n - 2);

        return v[n];
    }
    /*
    int climbStairs(int n) {
        if (n == 1 || n == 2) return n;

        return climbStairs(n - 1) + climbStairs(n - 2);
    }*/
};
// @lc code=end
