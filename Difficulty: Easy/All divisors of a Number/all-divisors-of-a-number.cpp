//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void print_divisors(int N) {
        // Code here.
        vector<int> ans;
        for(int i = 1; i*i<=N; i++){
            if(N%i == 0){
                ans.push_back(i);
                if(N/i != i) ans.push_back(N/i);
            }
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i<ans.size(); i++){
            cout<<ans[i]<<" ";
        }
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        ob.print_divisors(n);
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends