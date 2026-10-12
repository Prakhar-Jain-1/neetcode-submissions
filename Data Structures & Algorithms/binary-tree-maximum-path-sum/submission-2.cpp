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
    int ans = INT_MIN;
    int path(TreeNode* root){
        if(!root) return 0;
        int i = path(root->left);
        int j = path(root->right);
        // cerr<<root->val<<" "<<i<<" "<<j<<" "<<ans<<endl;
        if(i<0) i = 0;
        if(j<0) j = 0;
        ans = max(i + j + root->val, ans);
        return max(i,j) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        path(root);
        return ans;
    }
};
