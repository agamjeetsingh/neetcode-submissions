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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;

        helper(res, root);

        return res == 0 ? 0 : res - 1;
    }

    int helper(int& res, TreeNode* root) {
        if (!root) return 0;

        int max_depth_left = helper(res, root->left);
        int max_depth_right = helper(res, root->right);

        res = max(res, 1 + max_depth_left + max_depth_right);
        return 1 + max(max_depth_left, max_depth_right);
    }
};
