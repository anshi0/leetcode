class Solution {
public:
    int largestRectangleArea(vector<int> &height) {

        height.push_back(0);
        int n = height.size();
        vector<int> inds;

        int res = 0;
        for (int k = 0; k < n; k++) {
            while (inds.size() > 0 && height[inds.back()] >= height[k]) {
                int h = height[inds.back()];
                inds.pop_back();
                int diff = inds.size() > 0 ? inds.back() : -1;
                if (h * (k - diff - 1) > res) {
                    res = h * (k - diff - 1);
                }
            }
            inds.push_back(k);
        }
        return res;
    }
}; 