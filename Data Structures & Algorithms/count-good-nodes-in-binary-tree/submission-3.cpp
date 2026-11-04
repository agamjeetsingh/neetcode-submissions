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
        int res = 0;
        helper(root, res, INT_MIN);
        return res;
    }

    void helper(TreeNode* root, int& res, int curr_max) {
        if (!root) return;

        if (root->val >= curr_max) res++;
        curr_max = max(curr_max, root->val);

        helper(root->left, res, curr_max);
        helper(root->right, res, curr_max);
    }
};
