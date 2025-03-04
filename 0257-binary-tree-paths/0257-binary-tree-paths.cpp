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
    bool getPath(TreeNode* root, string &path, vector<string> &ans){
        if(!root) return false;
        string oriPath = path;
        if(!path.empty()) path += "->";
        path += to_string(root->val);
        if(root->left == NULL && root->right == NULL) ans.push_back(path);
        if(getPath(root->left, path, ans) || getPath(root->right, path, ans)) return true;
        path = oriPath;
        return false;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        vector<string> ans;
        getPath(root, path, ans);
        return ans;
    }
};