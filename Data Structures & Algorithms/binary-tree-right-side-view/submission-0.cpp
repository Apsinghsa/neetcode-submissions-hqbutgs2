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
    unordered_map<int,int> mp;
    int level = 0;
    vector<int> result;
    
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};

        level++;
        if(mp[level]) {
            vector<int> r = rightSideView(root->right);
            vector<int> l = rightSideView(root->left);
        }
        else {
            result.push_back(root->val);
            mp[level]++;
            vector<int> r = rightSideView(root->right);
            vector<int> l = rightSideView(root->left); 
        }   
        level--;

        return result;

    }
};
