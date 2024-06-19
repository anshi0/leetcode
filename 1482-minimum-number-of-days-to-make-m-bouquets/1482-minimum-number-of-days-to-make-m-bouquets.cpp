class Solution {
public:
    int NumBouquets(vector<int> &bloomDay, int mid, int k){
        int num =0;
        int cnt =0;
        for(int i =0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= mid) cnt++;
            else cnt =0;
            if(cnt == k){
                num ++;
                cnt =0;
            }
        }
        return num;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        //if(bloomDay.size() < (m*k)) return -1;
        int low = 0;
        int high =0;
        for(int day:bloomDay){
            high = max(high, day);
        }
        int mini = -1;
        while(high>= low){
            int mid = (high +low)/2;
            if(NumBouquets(bloomDay, mid, k) >= m){
                mini = mid;
                high = mid -1;
            }
            else {
                low = mid +1;
            }
        }
        return mini;
        }
};