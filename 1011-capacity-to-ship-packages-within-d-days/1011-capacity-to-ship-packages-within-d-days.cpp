class Solution {
public:
    int maximumElement(vector<int> &nums){
        int maxi = INT_MIN;
        for(int i =0; i<nums.size(); i++){
            if(nums[i] > maxi) maxi = nums[i];
        }
        return maxi;
    }
    int capacity(vector<int> &weight, int capacity){
        int load =0;
        int day = 1;
        for(int i =0; i<weight.size(); i++){
            if((load + weight[i]) > capacity){
                day = day +1;
                load = weight[i];
            }
            else load += weight[i];
        }
        return day;
    }
    int shipWithinDays(vector<int>& nums, int days) {
        int low = maximumElement(nums);
        int sum =0;
        for(int i =0; i<nums.size(); i++){
            sum += nums[i];
        }
        int high = sum;
        while(high>= low){
            int mid = (high +low)/2;
            if(capacity(nums, mid) > days) low = mid+1;
            else high = mid -1;
        }
        return low;
    }
};