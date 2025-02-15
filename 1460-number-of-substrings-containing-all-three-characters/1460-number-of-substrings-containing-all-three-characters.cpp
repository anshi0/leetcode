class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastSeen[3] = {-1, -1, -1};
        int cnt =0;
        for(int i =0; i<s.size(); i++){
            lastSeen[s[i] - 'a'] = i;
            cnt = cnt + (1 + min(lastSeen[0], min(lastSeen[1], lastSeen[2])));
        }
        return cnt;
        // unordered_map<char, int> mpp;
        // for(int i=0; i<s.size(); i++){
        //     mpp.clear();
        //     for(int j =i; j<s.size(); j++){
        //         mpp[s[j]]++;
        //         if(mpp.find('a') != mpp.end() && mpp.find('b') != mpp.end() && mpp.find('c') != mpp.end()) cnt++;
        //     }
        // }
        // return cnt;
    }
};