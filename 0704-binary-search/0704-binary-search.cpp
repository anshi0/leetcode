class Solution {
public:
    int search(vector<int>& nums, int target) {
         int low = 0;
        int n = nums.size();
        int high = n-1;
        //if(n == 1 && nums[n-1] == target) return 0;
        while(high >= low){
            int mid = (low+high)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) low = mid+1;
            else high = mid -1;
        }
        return -1;
    }
};