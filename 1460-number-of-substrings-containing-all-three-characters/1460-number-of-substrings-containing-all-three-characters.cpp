class Solution {
public:
    
int numberOfSubstrings(string s) {
    int cnt = 0;
    unordered_map<char, int> mpp;
    int l = 0;  // Left pointer
    
    for (int r = 0; r < s.size(); r++) {
        mpp[s[r]]++;  // Expand the window
        
        while (mpp['a'] > 0 && mpp['b'] > 0 && mpp['c'] > 0) {  
            // If all three characters are present, add valid substrings
            cnt += s.size() - r;  // All substrings from l → r to end are valid
            
            mpp[s[l]]--;  // Shrink the window from the left
            l++;          // Move left pointer
        }
    }
    
    return cnt;
}
};