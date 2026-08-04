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
        if (!root) return 0;

        int res = 0;
        getMaxDepth(res, root);

        return res;
    }

    int getMaxDepth(int& res, TreeNode* root) {
        if (!root) return 0;

        int left = getMaxDepth(res, root->left);
        int right = getMaxDepth(res, root->right);

        res = max(res, left + right);
        return 1 + max(left, right);
    }
};
