/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;

// hash
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            int num = target - nums[i];
            if (m.find(num) != m.end())
                return vector<int>{m[num], i};
            m[nums[i]] = i;
        }
        return vector<int>{};
    }
};

// Accepted
// 29/29 cases passed (8 ms)
// Your runtime beats 96.79 % of cpp submissions
// Your memory usage beats 100 % of cpp submissions (8.1 MB)
// @lc code=end

