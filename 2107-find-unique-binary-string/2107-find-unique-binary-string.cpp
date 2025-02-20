class Solution {
public:
    bool permutation(unordered_map<string, int> &mpp, string &s, int n){
        if(s.size() == n){
            if(mpp.find(s) == mpp.end()) return true;
            return false;
        }
        s.push_back('0');
        if(permutation(mpp, s, n)) return true;
        s.pop_back();

        s.push_back('1');
        if(permutation(mpp, s, n)) return true;
        s.pop_back();
        return false;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string, int> mpp;
        int size = nums.size();
        for(int i =0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }
        string s = "";
        permutation(mpp, s, size);
        return s;
    }
};