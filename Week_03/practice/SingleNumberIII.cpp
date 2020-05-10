/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res(2, 0);
        int mask = 0, diff = 0;

        for (auto num : nums) 
            mask ^= num;

        diff = mask & (-mask);
        for (auto num : nums) {
            if (num & diff)
                res[0] ^= num;
            else
                res[1] ^= num;
        }

        return res;
    }
};
// @lc code=end
