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
    int res = INT_MIN;

    int maxPathSum(TreeNode* root) {
        res = root->val;

        helper(root);

        return res;
    }

    // returns maximum single directional path including this node, empty allowed
    int helper(TreeNode* root) {
        if (!root) return 0;

        int left = max(helper(root->left), 0);
        int right = max(helper(root->right), 0);

        res = max(res, left + right + root->val);

        return max(0, max(root->val + left, root->val + right));
    }
};
