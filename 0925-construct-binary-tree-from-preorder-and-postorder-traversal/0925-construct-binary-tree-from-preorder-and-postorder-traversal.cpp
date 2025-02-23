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
    TreeNode* construct(vector<int>& preorder, vector<int>& postorder, int& index, int l, int h, unordered_map<int, int>& postorderMap) {
        if (index >= preorder.size() || l > h) return nullptr;

        TreeNode* root = new TreeNode(preorder[index++]);
        if (l == h) return root;

        // Find left child index in postorder
        int leftChildIdx = postorderMap[preorder[index]];

        // Recursively construct left and right subtrees
        root->left = construct(preorder, postorder, index, l, leftChildIdx, postorderMap);
        root->right = construct(preorder, postorder, index, leftChildIdx + 1, h - 1, postorderMap);
        
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> postorderMap;
        for (int i = 0; i < postorder.size(); i++) {
            postorderMap[postorder[i]] = i;
        }
        int index = 0;
        return construct(preorder, postorder, index, 0, preorder.size() - 1, postorderMap);
    }
};
