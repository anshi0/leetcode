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
    void postOrder(TreeNode* root, vector<int> &post){
        if(root == NULL) return;
        postOrder(root->left, post);
        postOrder(root->right, post);
        post.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> post;
        postOrder(root, post);
        return post;
    }
};