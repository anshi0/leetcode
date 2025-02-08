class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int el = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, heights[el] * (nse - pse - 1));
            }
            st.push(i);
        }
        while (!st.empty()) {
            int nse = heights.size();
            int el = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, heights[el] * (nse - pse - 1));
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> heights(
            n, vector<int>(m, 0)); // Fix: Correct dimensions

        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    heights[i][j] =
                        (i == 0)
                            ? 1
                            : heights[i - 1][j] + 1; // Accumulate column height
                } else {
                    heights[i][j] =
                        0; // Reset column height if '0' is encountered
                }
            }
        }

        for (int i = 0; i < n;
             i++) { // Fix: Loop should go from 0 to n, not n-1
            maxArea = max(
                maxArea,
                largestRectangleArea(heights[i])); // Fix: Remove `int` keyword
        }

        return maxArea;
    }
};
