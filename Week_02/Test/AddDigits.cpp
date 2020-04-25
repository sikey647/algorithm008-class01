/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
   public:
    int addDigits(int num) {
        if (num <= 9) return num;
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return addDigits(sum);
    }
};
// @lc code=end
