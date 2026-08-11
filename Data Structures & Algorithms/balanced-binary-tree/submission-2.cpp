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
    int DepthDiff(TreeNode* root){
        if(!root) return 0;
        int lDepth = DepthDiff(root->left);
        int rDepth = DepthDiff(root->right);

        int diff = abs(lDepth-rDepth);

        if(diff>1 || lDepth==-1 || rDepth==-1) return -1;

        return 1+max(lDepth, rDepth);
    }
    bool isBalanced(TreeNode* root) {
        int a = DepthDiff(root);
        if (a<0) return false;
        return true;
    }
};
