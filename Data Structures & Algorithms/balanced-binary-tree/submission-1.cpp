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

        int left_height = helper(res, root->left);
        int right_height = helper(res, root->right);

        if (res) {
            res = abs(left_height - right_height) <= 1;
        }

        return 1 + max(left_height, right_height);
    }
};
