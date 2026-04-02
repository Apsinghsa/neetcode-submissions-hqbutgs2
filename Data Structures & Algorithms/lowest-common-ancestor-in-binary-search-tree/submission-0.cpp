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
    bool check(TreeNode* root, TreeNode* p, vector<TreeNode*>& path){
        if(!root) return false;
        if(root->val == p->val) {
            path.push_back(p);
            return true;
        }
        path.push_back(root);
        if(check(root->left, p, path) || check(root->right, p, path)){
            return true;
        }
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        TreeNode* result;
        check(root, p, path1);
        check(root, q, path2);
        // for(int i=0; i<min(path1.size(), path2.size()); i++){
        //     if(path1[i]->val!=path2[i]->val){
        //         result = path1[i-1];
        //         break;
        //     }
        // }
        int i =0;
        int n = path1.size(), m = path2.size();
        while(i<max(n,m)){
            if(i<n && i<m && path1[i]->val!=path2[i]->val){
                result = path1[i-1];
                break;
            }
            if(i==n || i==m){
                result = path1[i-1];
                break;
            }
            i++;
        }
        return result;
    }
};

