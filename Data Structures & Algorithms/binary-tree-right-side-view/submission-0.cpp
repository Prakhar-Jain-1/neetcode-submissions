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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<TreeNode*> l1,l2;
        if(root!=nullptr)
        l1.push_back(root);
        vector<vector<int>> ret;
        int level = 0;
        while(l1.size()!=0){
            ret.push_back({});
            for(TreeNode* n: l1){
                ret[level].push_back(n->val);
                if(n->left!=nullptr) l2.push_back(n->left);
                if(n->right!=nullptr) l2.push_back(n->right);
            }
            l1 = l2;
            l2.clear();
            level++;
        }
        return ret;
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> o = levelOrder(root);
        vector<int>ret;
        for(vector<int> v:o){
            ret.push_back(v.back());
        }
        return ret;
    }
};
