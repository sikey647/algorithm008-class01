/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    int jump(vector<int>& nums) {
        int step = 0, fast = 0, end = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            fast = max(fast, i + nums[i]);
            if (i == end) {
                end = fast;
                step++;
            }
        }

        return step;
    }
};
// @lc code=end
