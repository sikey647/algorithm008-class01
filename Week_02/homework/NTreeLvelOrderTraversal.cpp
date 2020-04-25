/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N叉树的层序遍历
 */

// @lc code=start
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
   public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
   public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        _levelOrder(root, 0, res);
        return res;
    }

    void _levelOrder(Node* root, int depth, vector<vector<int>>& res) {
        if (!root) return;

        if (depth + 1 > res.size()) res.push_back(vector<int>{});

        res[depth].push_back(root->val);
        for (auto& elem : root->children) {
            _levelOrder(elem, depth + 1, res);
        }
    }
};
// @lc code=end
