//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<int> &vis, vector<vector<int>>&adj){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]) dfs(it, vis, adj);
        }
    }
    int numProvinces(vector<vector<int>> isConnected, int V) {
        // code here
        //convert to adjacency list
        vector<vector<int>> adj(V);
        for(int i = 0; i<isConnected.size(); i++){
            for(int j =0; j< isConnected.size(); j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(isConnected.size()+1, 0);
        int cnt = 0;
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                cnt ++;
                dfs(i, vis, adj);
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends