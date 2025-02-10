class Solution {
public:
    string clearDigits(string s) {
        string result;
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                if (!result.empty()) {
                    result.pop_back();  // Remove the previous character
                }
            } else {
                result.push_back(c);
            }
        }
        return result;
    }
};
