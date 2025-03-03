class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        bool sign = true;
        if(dividend >= 0  && divisor <0) sign =  false;
        else if(dividend <= 0 && divisor > 0) sign = false;
        long long int n = abs((long)dividend);
        long long int d =  abs((long)divisor);
        //divisor = abs(divisor);
        long long quotient = 0;
        while(n>=d){
            int cnt = 0;
            while(n >= (d<<(cnt+1))) cnt++;
            quotient += 1<<cnt;
            n = n - (d<<cnt);
        }
        if(quotient == 1<<31 && sign == true) return INT_MAX;
        if(quotient == 1<<31 && sign == false) return INT_MIN;
        return sign?(int)quotient:(-1 * (int)quotient);
    }
};