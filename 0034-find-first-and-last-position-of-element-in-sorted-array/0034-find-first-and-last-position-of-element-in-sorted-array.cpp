class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int cnt = 0;
        for(int i =0; i<nums.size(); i++){
            if(nums[i] == target) cnt = 1;
        }
        if(cnt ==0) return {-1, -1};
        int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        ans.push_back(lb);
        ans.push_back(ub-1);
        return ans;
    }
};