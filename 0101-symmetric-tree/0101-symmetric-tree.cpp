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
    bool isSymmetric(TreeNode* leftt , TreeNode* rightt){
        if(leftt == NULL || rightt == NULL) return leftt == rightt;
        if(leftt->val != rightt->val) return false;
        return isSymmetric(leftt->left, rightt->right) && isSymmetric(leftt->right, rightt->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root->left, root->right);
    }
};