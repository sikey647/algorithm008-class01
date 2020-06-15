/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;

        vector<int> a(1001, 0);
        for (int e : arr1) {
            a[e]++;
        }

        for (int e : arr2) {
            while (a[e]-- > 0) res.push_back(e);
        }

        for (int i = 0; i < 1001; i++) {
            while (a[i]-- > 0) res.push_back(i);
        }

        return res;
    }
};
// @lc code=end
