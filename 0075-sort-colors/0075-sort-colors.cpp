class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0=0, cnt1=0, cnt2=0;
        for(int i =0; i<nums.size(); i++){
            if(nums[i] == 0) cnt0 ++;
            else if(nums[i] == 1) cnt1++;
            else cnt2++;
        }
        int n = cnt0+ cnt1;
        for(int i=0; i<cnt0; i++){
            nums[i] = 0;
        }
        for(int i = cnt0; i<n; i++){
            nums[i] =1;
        }
        for(int i = n; i<nums.size(); i++){
            nums[i] = 2;
        }
    }
};