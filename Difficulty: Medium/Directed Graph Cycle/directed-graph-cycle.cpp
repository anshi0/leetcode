//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool dfs(int i, int V, vector<int> &vis, vector<int> &pathvis, vector<vector<int>>&adj){
        vis[i] = 1;
        pathvis[i] = 1;
        for(auto it : adj[i]){
            if(!vis[it]){
                if(dfs(it, V, vis, pathvis, adj)) return true;
            }
            else if(pathvis[it] == 1) return true;
        }
        pathvis[i] = 0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        vector<int> vis(V, 0);
        vector<int> pathvis(V, 0);
        for(int i =0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, V, vis, pathvis, adj)) return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends