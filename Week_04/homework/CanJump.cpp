/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int last = nums.size() - 1;
        for (int i = last; i >= 0; i--) {
            if (i + nums[i] >= last) last = i;
        }

        return last == 0;
    }
};
// @lc code=end
