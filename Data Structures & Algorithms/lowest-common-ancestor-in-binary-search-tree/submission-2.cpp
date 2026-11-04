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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return root;

        TreeNode* head = root;

        while (head) {
            if (p->val < head->val && q->val < head->val) {
                head = head->left;
            } else if (p->val > head->val && q->val > head->val) {
                head = head->right;
            } else {
                return head;
            }
        }
    }
};
