/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if (nums1.size() > nums2.size()) swap(nums1, nums2);

        unordered_map<int, int> m;
        for (auto& e : nums1) m[e]++;

        for (auto& e : nums2) {
            if (m[e] > 0) {
                res.push_back(e);
                m[e]--;
            }
        }

        return res;
    }
};
// @lc code=end
