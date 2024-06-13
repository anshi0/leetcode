class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans =0;
        int n = nums.size();
        int low =0;
        int high = n-1;
        if(target > nums[n-1]) return n;
        while(high >= low){
            int mid = (low + high)/2;
            if(nums[mid] >= target) {
                ans = mid;
                high = mid -1;
            }
            else low = mid +1;
        }
        return ans;
    }
};