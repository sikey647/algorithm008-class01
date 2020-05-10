/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;

        // 初始化边界
        int up = 0, down = matrix.size() - 1, left = 0,
            right = matrix[0].size() - 1;

        while (true) {
            // 从左向右移动
            for (int i = left; i <= right; ++i) res.push_back(matrix[up][i]);
            // 更新上边界
            if (++up > down) break;

            // 从上向下移动
            for (int i = up; i <= down; ++i) res.push_back(matrix[i][right]);
            // 更新右边界
            if (--right < left) break;

            // 从右向左移动
            for (int i = right; i >= left; --i) res.push_back(matrix[down][i]);
            // 更新下边界
            if (--down < up) break;

            // 从下向上移动
            for (int i = down; i >= up; --i) res.push_back(matrix[i][left]);
            // 更新左边界
            if (++left > right) break;
        }

        return res;
    }
};
// @lc code=end
