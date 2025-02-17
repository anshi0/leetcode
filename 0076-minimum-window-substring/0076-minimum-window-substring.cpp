class Solution {
public:
    string minWindow(string s, string t) {
        int l =0, r= 0, minlen = INT_MAX, sIndex = -1, cnt =0;
        unordered_map<char, int> mpp;
        for(int i =0; i<t.size(); i++) mpp[t[i]]++;
        while(r<s.size()){
            if(mpp[s[r]] > 0) cnt++;
            mpp[s[r]] --;
            while(cnt == t.size() && l<=r){
                if(r-l+1<minlen){
                    minlen = r-l+1;
                    sIndex = l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        if(sIndex == -1) return "";
        return s.substr(sIndex, minlen);
    }
};