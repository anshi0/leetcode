class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1) return 0; // Handle edge case

        vector<bool> prime(n, true); // Use bool instead of int (less memory)
        prime[0] = prime[1] = false; // 0 and 1 are not primes

        for (int i = 2; i * i < n; i++) {
            if (prime[i]) {
                for (int j = i * i; j < n; j += i) {
                    prime[j] = false; // Mark multiples as non-prime
                }
            }
        }

        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (prime[i]) cnt++; // Count primes directly
        }

        return cnt; // No extra lookup
    }
};
