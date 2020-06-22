/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
    // 状态数组：f[i]为无序的整数数组从0到i个元素中的最长上升子序列的长度
    // DP方程： f[i] = max(f[j] + 1), j = {0, ..., i};
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        vector<int> dp(nums.size(), 1);
        int maxLen = 1;

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    maxLen = max(maxLen, dp[i]);
                }
            }
        }

        return maxLen;
    }
};
// @lc code=end
