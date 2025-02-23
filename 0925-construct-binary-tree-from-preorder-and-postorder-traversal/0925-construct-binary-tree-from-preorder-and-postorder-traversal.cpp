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
    TreeNode* construct(vector<int>& preorder, vector<int>& postorder, vector<int>& index, int l, int h, unordered_map<int, int>& postMap) {
        if (index[0] >= preorder.size() || l > h) return NULL;
        
        TreeNode* root = new TreeNode(preorder[index[0]++]);
        if (l == h) return root;

        int i = postMap[preorder[index[0]]]; // O(1) lookup instead of O(N) search

        root->left = construct(preorder, postorder, index, l, i, postMap);
        root->right = construct(preorder, postorder, index, i + 1, h - 1, postMap);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> postMap;
        for (int i = 0; i < postorder.size(); i++) {
            postMap[postorder[i]] = i;
        }
        vector<int> index{0};
        return construct(preorder, postorder, index, 0, preorder.size() - 1, postMap);
    }
};
