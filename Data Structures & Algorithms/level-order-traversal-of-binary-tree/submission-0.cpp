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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>> result;
        queue<TreeNode*> q; 
        TreeNode* cur;

        q.push(root);
        result.push_back({root->val});

        while(!q.empty()){
            int s = q.size();
            vector<int> lvl;
            while(s--){
                cur = q.front();
                q.pop();
                if(cur->left){
                    q.push(cur->left);
                    lvl.push_back(cur->left->val);
                }
                if(cur->right){
                    q.push(cur->right);
                    lvl.push_back(cur->right->val);
                }
            }
            if(!lvl.empty()){
                result.push_back(lvl);
            }
        }

        return result;
    }
};