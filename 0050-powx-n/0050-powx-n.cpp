class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long m = abs((long long)n);
        while(m>0){
            if(m%2 == 1){
                ans = ans * x;
                m = m-1;
            }
            else {
                m = m/2;
                x = x*x;
            }

        }
        if(n<0) ans =  1.0/ans;
        return ans;
        // double ans = 1.0;
        // long long nn = n;
        // if (nn < 0)
        //     nn = -1 * nn;
        // while (nn) {
        //     if (nn % 2) {
        //         ans = ans * x;
        //         nn = nn - 1;
        //     } else {
        //         x = x * x;
        //         nn = nn / 2;
        //     }
        // }
        // if (n < 0)
        //     ans = (double)(1.0) / (double)(ans);
        // return ans;
    }
};