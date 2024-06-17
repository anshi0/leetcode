class Solution {
public:
    bool judgeSquareSum(int c) {
       long long low = 0;
        long long high = sqrt(c);
        while(high >= low){
            long long x = low*low;
            long long y = high*high;
            if((x + y) == c) return true;
            else if((x + y) > c) high--;
            else low ++;
        }
        return false;
    }
};