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
        int count = 0;
        return inOrder(root, count, k).second;
    }

    pair<bool, int> inOrder(TreeNode* root, int& count, int k) {
        if (!root) return {false, 0};
        auto [foundLeft, ansLeft] = inOrder(root->left, count, k);
        if (foundLeft) return {foundLeft, ansLeft};

        if (++count == k) return {true, root->val};

        auto [foundRight, ansRight] = inOrder(root->right, count, k);
        if (foundRight) return {foundRight, ansRight};
        
        return {false, 0};
    }
};
