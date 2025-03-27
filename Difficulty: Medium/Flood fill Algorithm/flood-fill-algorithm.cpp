//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
                                      int original=image[sr][sc];
        if(original==color) return image;
        dfs(image,sr,sc,color,original);

        return image;
        // Code here
    }
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int original){
        int m=image.size();
        int n=image[0].size();
        if(sr<0||sr>=m||sc<0||sc>=n||image[sr][sc]!=original) return;
        image[sr][sc]=color;
        dfs(image,sr-1,sc,color,original);
        dfs(image,sr+1,sc,color,original);
        dfs(image,sr,sc-1,color,original);
        dfs(image,sr,sc+1,color,original);
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends