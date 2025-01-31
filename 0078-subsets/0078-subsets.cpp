class Solution {
public:
    // void subsequences(int i, vector<int>& nums, vector<vector<int>> &ans, vector<int> &subset){
    //     if(i>= nums.size()){
    //         ans.push_back(subset);
    //         return;
    //     }
    //     subset.push_back(nums[i]);
    //     subsequences(i+1, nums, ans, subset);
    //     subset.pop_back();
    //     subsequences(i+1, nums, ans, subset);
    // }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subset = 1<<n;
        
        vector<vector<int>> ans;
        for(int number = 0; number<subset; number++){
            vector<int> list;
            for(int i =0; i<n; i++){
                if(number&(1<<i)) list.push_back(nums[i]);
            }
            ans.push_back(list);
        }
        // vector<vector<int>> ans;
        // vector<int> subset;
        // subsequences(0, nums, ans, subset);
        return ans;
    }
};