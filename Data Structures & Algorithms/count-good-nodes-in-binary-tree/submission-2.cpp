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
    int goodNodes(TreeNode* root) {
        return helper(root, INT_MIN);
    }

    int helper(TreeNode* root, int currentMin) {
        if (!root) return 0;

        int newMin = max(root->val, currentMin);
        int left = helper(root->left, newMin);
        int right = helper(root->right, newMin);

        return left + right + (root->val >= currentMin ? 1 : 0);
    }
};
