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
    int diameter = 0;

    int maxDepth(TreeNode* root){
        if(!root) return 0;
        int lDepth = maxDepth(root->left);
        int rDepth = maxDepth(root->right);

        int dia = lDepth+rDepth;

        diameter = max(diameter, dia);

        return 1+ max(lDepth, rDepth);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return diameter;
    }
};
