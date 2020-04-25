/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        _preorderTraversal(root, res);
        return res;
    }

    void _preorderTraversal(TreeNode* root, vector<int>& res) {
        if (!root) return;
        res.push_back(root->val);
        _preorderTraversal(root->left, res);
        _preorderTraversal(root->right, res);
    }
};
// @lc code=end
