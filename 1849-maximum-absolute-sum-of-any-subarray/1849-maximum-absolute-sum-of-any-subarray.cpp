class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum =0;
        int mini = 0;
        int maxi =  0;
        for(int i =0; i<nums.size(); i++){
            sum += nums[i];
            if(sum > maxi) maxi = sum;
            if(sum<mini) mini = sum;
        }
        return abs(maxi-mini);
    }
};