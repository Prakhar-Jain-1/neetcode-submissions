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
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        while(!q.empty()){
            TreeNode* k = q.front().first;
            int m = q.front().second;
            q.pop();
            if(k->left!=nullptr){
                q.push({k->left,max(k->left->val,m)});
            }
            if(k->right!=nullptr){
                q.push({k->right,max(k->right->val,m)});
            }
            if(k->val>=m){
                ans++;
            }
        }
        return ans;
    }
};
