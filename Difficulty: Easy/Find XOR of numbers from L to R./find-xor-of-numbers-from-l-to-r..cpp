//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int valXor(int n){
        if(n%4 == 1) return 1;
        else if(n %4 == 2) return n+1;
        else if(n%4 == 3) return 0;
        else return n;
        return 0;
    }
    int findXOR(int l, int r) {
        // complete the function here
        return valXor(l-1) ^ valXor(r);
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends