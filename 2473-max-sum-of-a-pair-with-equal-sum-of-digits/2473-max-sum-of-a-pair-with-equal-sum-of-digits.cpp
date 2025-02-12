class Solution {
public:
    int calculateDigits(int num){
        int digitSum = 0;
        while(num>0){
            digitSum += num%10;
            num = num/10;
        }
        return digitSum;
    }
    int maximumSum(vector<int>& nums) {
        vector<pair<int, int>> digitSumPairs;
        for(int numbers : nums){
            int digitSum = calculateDigits(numbers);
            digitSumPairs.push_back({digitSum, numbers}); 
        }
        sort(digitSumPairs.begin(), digitSumPairs.end());
        int maxi = -1;
        for(int i = 1; i<digitSumPairs.size(); i++){
            int curr = digitSumPairs[i].first;
            int prev = digitSumPairs[i-1].first;
            if(curr == prev) maxi = max(maxi, digitSumPairs[i].second + digitSumPairs[i-1].second);
        }
        return maxi;
    }
};