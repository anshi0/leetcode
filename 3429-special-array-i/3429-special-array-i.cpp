class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int sum  = 0;
        for(int j = 0; j<nums.size()-1; j++){
            sum = nums[j]+nums[j+1];
            if(sum % 2 == 0) return false;
        }
        return true;
    }
};