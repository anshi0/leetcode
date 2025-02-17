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
    void inOrder(TreeNode * node, vector<int> &inn){
        if(node == NULL) return;
        inOrder(node->left, inn);
        inn.push_back(node->val);
        inOrder(node->right, inn);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inn;
        inOrder(root, inn);
        return inn;
    }
};