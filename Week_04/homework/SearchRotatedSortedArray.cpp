/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if ((nums[left] <= nums[mid]) &&
                (target > nums[mid] || target < nums[left]))
                left = mid + 1;
            else if (nums[left] > target && nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }

        return left == right && nums[left] == target ? left : -1;
    }
};
// @lc code=end
