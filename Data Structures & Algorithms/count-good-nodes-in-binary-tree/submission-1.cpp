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
        if (!root) return 0;
        int res = 0;
        stack<pair<TreeNode*, int>> st;

        st.push({root, INT_MIN});

        while (!st.empty()) {
            auto [node, m] = st.top(); st.pop();

            if (node->val >= m) res++;

            int new_max = max(m, node->val);

            if (node->left) st.push({node->left, new_max});
            if (node->right) st.push({node->right, new_max});
        }
        
        return res;
    }
};
