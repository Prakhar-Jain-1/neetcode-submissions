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
    int i;

    void encode(TreeNode* root, string& s) {
        if (!root) {
            s += "N";
            return;
        }

        s += to_string(root->val);
        s += '#';

        encode(root->left, s);
        encode(root->right, s);
    }

    TreeNode* decode(const string& data) {
        if (i >= data.size()) return nullptr;

        if (data[i] == 'N') {
            i++;
            return nullptr;
        }

        int j = i;
        while (i < data.size() && data[i] != '#') {
            i++;
        }

        int num = stoi(data.substr(j, i - j));
        i++;  // Skip '#'

        TreeNode* root = new TreeNode(num);
        root->left = decode(data);
        root->right = decode(data);

        return root;
    }

public:
    string serialize(TreeNode* root) {
        string ret;
        encode(root, ret);
        return ret;
    }

    TreeNode* deserialize(string data) {
        i = 0;
        return decode(data);
    }
};
