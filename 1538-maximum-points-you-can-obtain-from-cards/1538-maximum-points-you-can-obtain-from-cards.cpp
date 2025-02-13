class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        if (k == cardPoints.size()) {  // Fixed assignment '=' to '=='
            for (int i = 0; i < cardPoints.size(); i++) {
                sum += cardPoints[i];
            }
            return sum;
        }

        int n = cardPoints.size();
        int l = k - 1;
        int r = n - 1;  // Fixed: r should be n-1 (last index)
        int lsum = 0;
        int rsum = 0;
        int maxi = 0;

        for (int i = 0; i < k; i++) {
            lsum += cardPoints[i];
        }
        sum = lsum; // Initialize sum correctly

        while (k >= 0) {  // Fixed condition: k should be >= 0
            maxi = max(maxi, sum);  // Compare before modifying sum
            if (l >= 0) {
                sum -= cardPoints[l];  // Remove leftmost element
                l--;
            }
            if (r >= 0) {
                sum += cardPoints[r];  // Add rightmost element
                r--;
            }
            k--;
        }

        return maxi;
    }
};
