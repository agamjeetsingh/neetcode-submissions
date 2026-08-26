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
        string res;
        queue<TreeNode*> s;
        s.push(root);
        
        while (!s.empty()) {
            TreeNode* top = s.front(); s.pop();

            if (top) {
                res += to_string(top->val);
                s.push(top->left);
                s.push(top->right);
            } else {
                res += "N";
            }
            res += "/";
        }

        // cout << res;

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string segment;

        queue<TreeNode*> q;

        TreeNode* currentParent = nullptr;
        TreeNode* res = nullptr;
        int timer = 1;

        while (getline(ss, segment, '/')) {
            if (segment.empty()) continue;

            if (segment == "N") {           
                if (--timer == 0 && !q.empty()) {
                    currentParent = q.front(); q.pop();
                    timer = 2;
                }
            } else {
                int value = stoi(segment);

                TreeNode* newNode = new TreeNode(value);

                if (!currentParent) {
                    res = newNode;
                }

                if (currentParent) {
                    if (timer == 2) {
                        currentParent->left = newNode;
                    } else if (timer == 1) {
                        currentParent->right = newNode;
                    }
                }

                q.push(newNode);
                
                if (--timer == 0) {
                    currentParent = q.front(); q.pop();
                    timer = 2;
                }
            }
        }
        return res;
    }
};
