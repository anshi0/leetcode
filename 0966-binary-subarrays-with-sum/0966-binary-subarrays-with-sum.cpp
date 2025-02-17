class Solution {
public:
    int numSubarrayslessGoal(vector<int>& nums, int goal){
        int cnt = 0;
        int sum = 0;
        int l=0, r = 0;
        while(r<nums.size()){
            sum += nums[r];
            while(sum > goal && l<= r){
                sum -= nums[l];
                l++;
            }
            cnt += r-l+1;
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numSubarrayslessGoal(nums, goal) - numSubarrayslessGoal(nums, goal-1);
    }
};