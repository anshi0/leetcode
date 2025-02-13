class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l =0;
        int r = 0;
        int maxlen = 0;
        //int len = 0;
        int k1 = k;
        while(r<nums.size()){
            if(nums[r] == 0) k1--;
            while(k1<0){
                if(nums[l] == 0) k1++;
                l++; // shrink from front
            }
            maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};