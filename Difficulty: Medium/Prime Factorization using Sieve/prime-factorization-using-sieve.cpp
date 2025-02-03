//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void sieve() {}

    vector<int> findPrimeFactors(int N) {

        // Write your code here
        vector<int> SPF(N+1);
        for(int i =0; i<=N; i++) SPF[i] = i;
        for(int i = 2; i<N+1; i++){
            if(SPF[i] == i){
                for(int j = max(i*i, i*2); j<=N; j+=i){
                    if(SPF[j] == j) SPF[j] = i;
                }
            }
        }
        vector<int> ans;
        while(N>1){
            ans.push_back(SPF[N]);
            N = N/SPF[N];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n;
        cin >> n;

        Solution obj;
        obj.sieve();
        vector<int> vec = obj.findPrimeFactors(n);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends