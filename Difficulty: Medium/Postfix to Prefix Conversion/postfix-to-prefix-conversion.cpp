//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToPre(string post_exp) {
        // Write your code here
        int i =0;
        stack<string> st;
        while(i<post_exp.size()){
            char c = post_exp[i];
            if((c>='A' && c<= 'Z') || (c>='a' && c<='z') || (c>='0' && c<='9')) st.push(string(1,c));
            else{
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();
                string conv = string(1,c) + t2 + t1;
                st.push(conv);
            }
            i++;
        }
        return st.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends