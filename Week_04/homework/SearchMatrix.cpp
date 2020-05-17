/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if (matrix.size() == 0) return false;

        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            int midVal = matrix[mid / n][mid % n];

            if (midVal == target)
                return true;
            else if (midVal > target)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return false;
    }
};
// @lc code=end
