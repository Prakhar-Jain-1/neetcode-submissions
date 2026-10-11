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
    int ans = 0;
public:
    int maxDepth(TreeNode* root){
        if(root == nullptr) return 0;
        int i = maxDepth(root->left), j = maxDepth(root->right);
        ans = max(i+j,ans);
        return max(i,j) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return ans;
    }
};
