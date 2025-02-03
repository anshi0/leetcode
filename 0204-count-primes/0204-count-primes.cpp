class Solution {
public:
    int countPrimes(int n) {
        if(n<=1) return 0;
        vector<int> prime(n, 1);
        prime[0]= prime[1] = 0;
        //for (int i = 2; i < n; i++) prime[i] = 1;
        for(int i = 2; i*i<n; i++){
            if(prime[i] == 1){
                for(int j = i*i; j<n; j = j+i) prime[j] = 0;
            }
        }
        int cnt = 0;
        for(int i = 2; i<n; i++){
            cnt += prime[i];
            prime[i] = cnt;
        }
        return prime[n-1];
    }
};

