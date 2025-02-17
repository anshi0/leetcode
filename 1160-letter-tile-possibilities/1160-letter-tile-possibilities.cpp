
class Solution {
public:
    void backtrack(unordered_map<char, int>& freq, string current, unordered_set<string>& result) {
        if (!current.empty()) result.insert(current);  // Store unique sequences
        
        for (auto& pair : freq) {
            if (pair.second > 0) {
                pair.second--;  // Use a tile
                backtrack(freq, current + pair.first, result);
                pair.second++;  // Backtrack
            }
        }
    }

    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freq;
        for (char c : tiles) freq[c]++;  // Count occurrences of each character

        unordered_set<string> result;
        backtrack(freq, "", result);
        
        return result.size();
    }
};
