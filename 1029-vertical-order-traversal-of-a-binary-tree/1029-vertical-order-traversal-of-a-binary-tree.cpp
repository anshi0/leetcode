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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> mp;
        // queue<pair<TreeNode*,pair<int,int>>>q;
        // map<int,pair<int,multiset<int>>>mp;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto current = q.front();
            q.pop();
            TreeNode * node = current.first;
            int x = current.second.first;
            int y = current.second.second;
            mp[x][y].insert(node->val);
            // mp[x][y] = current.first->val;
            if(node->left != nullptr)
            {
                q.push({node->left , {x-1,y+1}});
            }
            if(node->right  != nullptr)
            {
                q.push({node->right , {x+1,y+1}});
            }
        }
        for(auto j:mp)
        {
            vector<int>v;
            for(auto k:j.second)
            {
                v.insert(v.end(),k.second.begin(),k.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};