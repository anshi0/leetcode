class Solution {
public:
    int numSubarrayslessGoal(vector<int>& nums, int goal){
        int cnt = 0;
        int sum = 0;
        int l=0, r = 0;
        while(r<nums.size()){
            sum += (nums[r]%2);
            while(sum > goal && l<= r){
                sum -= (nums[l]%2);
                l++;
            }
            cnt += r-l+1;
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return numSubarrayslessGoal(nums, k) - numSubarrayslessGoal(nums, k-1);
    }
};