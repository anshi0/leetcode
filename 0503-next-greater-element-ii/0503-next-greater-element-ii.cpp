class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {


/// this has a time complexity of o(N^2) and SC of O(N)
        //   vector<int> nge(nums.size(), -1);
        //   for (int i = 0; i < nums.size(); i++) {
        //     for (int j = i+1; j < i+nums.size(); j++) {
        //         int index = j % nums.size();
        //         if (nums[index] > nums[i]) {
        //             nge[i] = nums[index];
        //             break;
        //         }
        //     }
        //   }
        //   return nge;



        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;
        for(int i = n * 2 - 1; i >=0 ; i--) {
            while (!st.empty() && st.top() <= nums[i % n]) {
            st.pop();
        }
        
        // Only store results for the first pass (i < n)
        if (i < n) {
            if (!st.empty()) {
                res[i] = st.top();
            }
        }
        st.push(nums[i % n]);           
        }
        return res;
    }
};