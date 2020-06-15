/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.size() == 0) return res;

        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });

        for (auto& elem : intervals) {
            if (res.empty() || elem[0] > res.back()[1]) {
                res.push_back(elem);
            } else {
                res.back()[1] = max(elem[1], res.back()[1]);
            }
        }

        return res;
    }
};
// @lc code=end
