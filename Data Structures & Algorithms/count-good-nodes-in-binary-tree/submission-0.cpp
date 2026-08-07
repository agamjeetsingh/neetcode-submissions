/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int res = 0;

    int goodNodes(TreeNode* root) {
        helper(root, INT_MIN);

        return res;
    }

    void helper(TreeNode* root, int m) {
        if (!root) return;

        if (root->val >= m) res++;

        int new_max = max(m, root->val);

        helper(root->left, new_max);
        helper(root->right, new_max);
    }
};
