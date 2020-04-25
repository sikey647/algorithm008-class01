/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        _inorderTraversal(root, res);
        return res;
    }

    void _inorderTraversal(TreeNode* root, vector<int>& res) {
        if (!root) return;
        _inorderTraversal(root->left, res);
        res.push_back(root->val);
        _inorderTraversal(root->right, res);
    }
};
// @lc code=end
