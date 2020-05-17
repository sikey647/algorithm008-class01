/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if (!root) return res;

        queue<TreeNode *> _queue;
        _queue.push(root);

        while (!_queue.empty()) {
            vector<int> sub;
            int size = _queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = _queue.front();
                _queue.pop();
                sub.push_back(node->val);
                if (node->left) _queue.push(node->left);
                if (node->right) _queue.push(node->right);
            }

            if (sub.size()) res.push_back(sub);
        }

        return res;
    }
};
// @lc code=end
