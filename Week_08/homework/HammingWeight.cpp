/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
#include <stdint.h>

class Solution {
   public:
    int hammingWeight(uint32_t n) {
        // int count = 0;
        // uint32_t mask = 1;

        // for (int i = 0; i < 32; i++) {
        //     if (n & mask) count++;
        //     mask <<= 1;
        // }

        // return count;

        int count = 0;

        while (n) {
            count++;
            n = n & (n - 1);
        }

        return count;
    }
};
// @lc code=end
