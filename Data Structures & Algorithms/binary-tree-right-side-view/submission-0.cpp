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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        vector<vector<int>> notRes = levelOrder(root);
        for (vector<int>& vec: notRes) {
            res.push_back(vec.back());
        }
        return res;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        vector<int> curr;
        
        int size = 1;
        int nextLevelSize = 0;

        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            TreeNode* top = q.front(); q.pop();
            curr.push_back(top->val);

            if (top->left) {
                q.push(top->left); nextLevelSize++;
            }
            if (top->right) {
                q.push(top->right); nextLevelSize++;
            }

            if (--size == 0) {
                size = nextLevelSize;
                nextLevelSize = 0;

                res.push_back(curr);
                curr.clear();
            }
        }

        return res;
    }
};
