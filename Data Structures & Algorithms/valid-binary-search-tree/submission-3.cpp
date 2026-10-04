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
    bool isValidBST(TreeNode* root) {
        return helper(root, INT_MAX, INT_MIN);
    }

    bool helper(TreeNode* root, int upperBound, int lowerBound) {
        if (!root) return true;

        if (root->val > upperBound || root->val < lowerBound) return false;

        return helper(root->left, min(root->val, upperBound), lowerBound) && helper(root->right, upperBound, max(root->val, lowerBound));
    }
};
