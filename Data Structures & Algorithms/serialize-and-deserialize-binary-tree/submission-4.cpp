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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* front = q.front(); q.pop();
            if (front) {
                res += to_string(front->val);

                q.push(front->left);
                q.push(front->right);
            } else {
                res += "N";
            }
            res += ",";
        }
        cout << res;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        char delimiter = ',';
        string token;

        queue<TreeNode*> parents;
        TreeNode* res = nullptr;
        int step = 0;
        
        while (getline(ss, token, delimiter)) {
            if (parents.empty()) {
                parents.push(new TreeNode(stoi(token)));
                res = parents.front();
            } else {
                TreeNode* child = nullptr;
                if (token != "N") {
                    child = new TreeNode(stoi(token));
                }

                if (++step == 1) {
                    parents.front()->left = child;
                } else {
                    step = 0;
                    parents.front()->right = child;
                    parents.pop();
                }

                if (child) parents.push(child);
            }
        }

        return res;
    }
};
