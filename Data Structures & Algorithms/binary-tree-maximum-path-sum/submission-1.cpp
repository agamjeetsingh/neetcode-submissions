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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        
        helper(root, res);

        return res;
    }

    int helper(TreeNode* root, int& res) {
        if (!root) return 0;

        int left = helper(root->left, res);
        int right = helper(root->right, res);

        res = max(res, root->val + max(left, 0) + max(right, 0));

        return root->val + max(max(left, right), 0);
    }
};
