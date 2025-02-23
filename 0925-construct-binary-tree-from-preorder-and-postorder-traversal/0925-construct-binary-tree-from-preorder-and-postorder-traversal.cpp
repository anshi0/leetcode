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
    int index = 0;
    TreeNode* build(vector<int>& pre, vector<int>& post, int s, int e, unordered_map<int, int>& postMap) {
        if (s > e || index >= pre.size()) return NULL;
        TreeNode* root = new TreeNode(pre[index++]);
        if (s == e) return root;
        int ni = postMap[pre[index]];  // O(1) lookup instead of O(N) search
        root->left = build(pre, post, s, ni, postMap);
        root->right = build(pre, post, ni + 1, e - 1, postMap);
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> postMap;
        for (int i = 0; i < postorder.size(); i++) {
            postMap[postorder[i]] = i;
        }
        return build(preorder, postorder, 0, preorder.size() - 1, postMap);
    }
};
