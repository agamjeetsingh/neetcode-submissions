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
        return isValidBSTwithMaxMin(root, INT_MIN, INT_MAX);
    }

    bool isValidBSTwithMaxMin(TreeNode* root, int min_, int max_) {
        if (!root) return true;

        if (root->val < min_ || root->val > max_) return false;

        return isValidBSTwithMaxMin(root->left, min_, min(max_, root->val)) && isValidBSTwithMaxMin(root->right, max(min_, root->val), max_);
    }
};
