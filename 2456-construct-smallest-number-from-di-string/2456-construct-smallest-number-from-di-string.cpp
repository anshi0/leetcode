class Solution {
public:
    bool backtrack(string& path, string pattern, string &result, vector<bool> &visited) {
        if (path.size() == pattern.size() + 1) {
            result = path;
            return true;
        }
        for (int i = 1; i <= 9; i++) {
            if (visited[i])
                continue;
            int pathIndex = path.size() - 1;
            if (pathIndex == -1 ||
                (pattern[pathIndex] == 'I' &&
                 path[pathIndex] < (char)(i + '0')) ||
                (pattern[pathIndex] == 'D' &&
                 path[pathIndex] > (char)(i + '0'))) {
                visited[i] = true;
                path += (char)(i + '0');
                if (backtrack(path, pattern, result, visited))
                    return true;
                path.pop_back();
                visited[i] = false;
            }
        }
        return false;
    }
    string smallestNumber(string pattern) {
        vector<bool> visited(10, false);
        string result = "";

        string path = "";
        backtrack(path, pattern, result, visited);
        return result;
    }
};