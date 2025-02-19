class Solution {
public:
    void permutationString(int n, string curr, vector<string> &happy){
        if(curr.size() == n){
            happy.push_back(curr);
            return;
        }
        for(char currCh = 'a' ; currCh <= 'c'; currCh++){
            if(curr.size() > 0 && curr.back() == currCh) continue;
            permutationString(n, curr+currCh, happy);
        }
    }
    string getHappyString(int n, int k) {
        string Curr = "";
        vector<string> happy;
        permutationString(n, Curr, happy);
        if(happy.size() < k) return ""; //that many permutations doesnot exist
        sort(happy.begin(), happy.end());
        return happy[k-1];
    }
};