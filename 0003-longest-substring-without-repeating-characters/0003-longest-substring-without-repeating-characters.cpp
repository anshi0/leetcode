class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256, -1);
        int n = s.size();
        int l = 0;
        int r = 0;
        int maxi = 0;  // Fixed initialization

        while (r < n) {
            if (mpp[s[r]] >= l) {  // Fixed condition
                l = mpp[s[r]] + 1;
            }
            
            int len = r - l + 1;  // Fixed length calculation
            maxi = max(maxi, len);
            mpp[s[r]] = r;
            r++;
        }

        return maxi;
    }
};
