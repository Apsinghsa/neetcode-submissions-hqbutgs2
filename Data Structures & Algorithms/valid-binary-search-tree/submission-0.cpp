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
    bool isValidBST(TreeNode* root, long lowLimit = LONG_MIN, long upLimit = LONG_MAX) {
        if (!root) return true;

        if (root->val <= lowLimit || root->val >= upLimit) return false;

        bool lCheck = isValidBST(root->left, lowLimit, root->val);
        bool rCheck = isValidBST(root->right, root->val, upLimit);

        return lCheck && rCheck;
    }
};
