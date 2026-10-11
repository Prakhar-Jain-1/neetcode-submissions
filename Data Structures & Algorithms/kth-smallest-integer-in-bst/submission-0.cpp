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
    int cnt = 0;
    int k;
    TreeNode* ans;
    void dfs(TreeNode* node){
        if(!node){
            // cnt++;
            return;
        }
        dfs(node->left);
        cnt++;
        if(cnt == k){
            ans = node;
            // return;
        }
        dfs(node->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        dfs(root);
        return this->ans->val;
    }
};
