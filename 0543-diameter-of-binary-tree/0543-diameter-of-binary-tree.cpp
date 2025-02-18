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
    int findMax(TreeNode* root, int &dia){
        if(root == NULL) return 0;
        int LH = findMax(root->left, dia);
        int RH = findMax(root->right, dia);
        dia = max(dia, LH+RH);
        return 1 + max(LH, RH);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        findMax(root, dia);
        return dia;
    }
};