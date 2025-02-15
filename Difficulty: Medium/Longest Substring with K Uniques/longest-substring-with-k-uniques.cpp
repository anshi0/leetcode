//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // your code here
        if(k>s.size()) return -1;
        int maxlen = -1;
        unordered_map<char, int> mpp;
        int l =0;
        int r =0 ;
        while(r< s.size()){
            mpp[s[r]]++;
            if(mpp.size() > k){
                l++;
                mpp[s[l-1]]--;
                if(mpp[s[l-1]] == 0) mpp.erase(s[l-1]);
            }
            if(mpp.size() == k) maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends