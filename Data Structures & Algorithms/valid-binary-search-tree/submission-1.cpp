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
    bool pokemon(TreeNode* node, int lower, int upper){
        if(!node) return true;
        if(node->val<=lower or node->val>=upper) return false;
        return pokemon(node->left, lower, node->val) and pokemon(node->right, node->val,upper);
    }
public:
    bool isValidBST(TreeNode* root) {
        return pokemon(root, INT_MIN, INT_MAX);
    }
};
