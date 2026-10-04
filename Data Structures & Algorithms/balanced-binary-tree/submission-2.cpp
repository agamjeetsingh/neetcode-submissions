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
    bool isBalanced(TreeNode* root) {
        bool res = true;

        helper(res, root);

        return res;
    }

    int helper(bool& res, TreeNode* root) {
        if (!root) return 0;

        int left = helper(res, root->left);
        int right = helper(res, root->right);

        res = res && abs(left - right) <= 1;

        return 1 + max(left, right);
    }
};
