class Solution {
public:
    int maximumElement(vector<int> &nums){
        int maxi = INT_MIN;
        for(int i =0; i<nums.size(); i++){
            if(nums[i] > maxi) maxi = nums[i];
        }
        return maxi;
    }
    int sumDivisor(vector<int>&nums, int mid){
        int sum =0;
        for(int i = 0; i<nums.size(); i++){
            sum = sum + ceil((double)nums[i]/(double)mid);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low =1;
        int high = maximumElement(nums);
        int ans = 0;
        while(high>= low){
            int mid = (high+low)/2;
            if(sumDivisor(nums, mid) <= threshold) {
                high = mid-1;
                ans = mid;
            }
            else low = mid +1;
        }
        return ans;
    }
};