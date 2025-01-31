class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int XORR = 0;
        for(int i = 0; i<nums.size(); i++){
            XORR = XORR ^ nums[i];
        }
        return XORR;
    }
};