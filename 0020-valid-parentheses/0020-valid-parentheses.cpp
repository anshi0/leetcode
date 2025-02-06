class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int it : s){
            if(it == '(' || it == '[' || it == '{') st.push(it);
            else{
                if(st.empty() == true) return false;
                char ch = st.top();
                st.pop();
                if((it == ')' && ch == '(') || (it == ']' && ch == '[') || (it == '}' && ch == '{')) continue;
                else return false;
            }
        }
        if(st.empty() == true) return true;
        return false;
    }
};