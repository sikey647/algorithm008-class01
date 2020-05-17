/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 */

#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    vector<int> largestValues(TreeNode *root) {
        vector<int> res;
        if (!root) return res;

        queue<TreeNode *> _queue;
        _queue.push(root);

        while (!_queue.empty()) {
            int size = _queue.size();
            int max = _queue.front()->val;
            for (int i = 0; i < size; i++) {
                TreeNode *node = _queue.front();
                _queue.pop();
                if (node->val > max) max = node->val;
                if (node->left) _queue.push(node->left);
                if (node->right) _queue.push(node->right);
            }
            res.push_back(max);
        }

        return res;
    }
};
// @lc code=end
