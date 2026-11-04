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
    int kthSmallest(TreeNode* root, int k) {
        int res;
        int count = 0;
        inOrder(root, k, res, count);
        return res;
    }

    void inOrder(TreeNode* root, int k, int& res, int& count) {
        if (!root) return;
        
        inOrder(root->left, k, res, count);

        if (count++ > k) return;
        
        if (count == k) {
            res = root->val;
            return;
        }

        inOrder(root->right, k, res, count);
    }
};
