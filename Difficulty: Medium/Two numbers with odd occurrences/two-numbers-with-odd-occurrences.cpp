//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int nums[], long long int N)  
    {
        // code here
        long long int XORR = 0;
        for(int i =0; i<N; i++) XORR = XORR^nums[i];
        int rightmost = (XORR & (XORR-1)) ^ XORR;
        long long int b1 = 0;
        long long int b2 = 0;
        for(int i =0; i<N; i++){
            if(nums[i] & rightmost) b1 = b1^nums[i];
            else b2 = b2^nums[i];
        }
        if(b2>b1) return {b2, b1};
        return {b1,b2};
        
        // long long int ans=0;
        // for(int i=0;i<N;i++){
        //     ans= ans ^ Arr[i];
        // }
        
        // int rightMost= (ans & (ans-1)) ^ ans;
        // long long int b1=0, b2=0;
        // for(int i=0;i<N;i++){
        //     if(Arr[i] & rightMost){
        //         b1= b1 ^ Arr[i];
        //     }
        //     else{
        //         b2= b2 ^ Arr[i];
        //     }
        // }
        // if(b1 < b2) return {b2,b1};
        // return {b1,b2};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends