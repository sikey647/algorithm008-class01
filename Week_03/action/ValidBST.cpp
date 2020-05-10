/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    bool isValidBST(TreeNode *root) {
        return _isValidBST(root, nullptr, nullptr);
    }

    bool _isValidBST(TreeNode *root, TreeNode *min, TreeNode *max) {
        if (!root) return true;

        if (min && root->val <= min->val || max && root->val >= max->val)
            return false;

        return _isValidBST(root->left, min, root) &&
               _isValidBST(root->right, root, max);
    }
};
// @lc code=end
