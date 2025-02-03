class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1) return 0; // Edge case

        vector<bool> prime(n, true); // Use bool for efficiency
        prime[0] = prime[1] = false; // 0 and 1 are not primes

        for (int i = 2; i * i < n; i++) {
            if (prime[i]) {
                for (int j = i * i; j < n; j += i) {
                    prime[j] = false; // Mark multiples of i as non-prime
                }
            }
        }

        vector<int> prefix(n, 0); // Store prefix count of primes
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            cnt += prime[i];
            prefix[i] = cnt; // Store cumulative count
        }

        return prefix[n-1]; // Return precomputed prime count
    }
};
