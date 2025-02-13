class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        if(k == cardPoints.size()){
            for(int i =0; i< cardPoints.size(); i++){
                sum += cardPoints[i];
            }
            return sum;
        }
        int n = cardPoints.size();
        int l = k-1;
        int r = n-1;
        int lsum = 0;
        int rsum = 0;
        int maxi = 0;
        for(int i =0; i<k; i++){
            lsum += cardPoints[i];
        }
        sum = lsum;
        while(k >= 0){
            maxi = max(maxi, sum);
            if(l>= 0){
                sum -= cardPoints[l];
                l--;
            }
            if(r<n && r>=0){
                sum += cardPoints[r];
                r--;
            }
            k--;
        }
        return maxi;
    }
};