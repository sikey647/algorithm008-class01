/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    void sortColors(vector<int>& nums) {
        int zeroIndex = 0, twoIndex = nums.size() - 1;
        for (int i = 0; i <= twoIndex; i++) {
            if (nums[i] == 0) swap(nums[zeroIndex++], nums[i]);
            if (nums[i] == 2) swap(nums[twoIndex--], nums[i--]);
        }
    }
};
// @lc code=end
