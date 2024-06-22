class Solution {
public:
    int noStu(vector<int> & arr, int pages){
    int stu =1;
    long long pagestu = 0;
    for(int i =0; i<arr.size(); i++){
        if(pagestu+ arr[i] <= pages) pagestu += arr[i];
        else {
            stu++;
            pagestu = arr[i];
        }
    }
    return stu;
}

int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(m>n) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while(high >= low){
        int mid = (high +low)/2;
        int cntStu = noStu(arr, mid);
        if(cntStu > m) low = mid +1;
        else high = mid-1;
    }
    return low;
}
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        return findPages(nums, n, k);
    }
};