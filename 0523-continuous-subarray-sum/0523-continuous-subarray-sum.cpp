class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;
        int n = nums.size(); // size of the given array.

        unordered_map<int, int> remainderMap;
        remainderMap[0] = -1; // Handle the case where the sum is directly a multiple of k

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (k != 0) sum %= k; // Only take modulo k if k is not zero

            if (remainderMap.find(sum) != remainderMap.end()) {
                if (i - remainderMap[sum] > 1) return true; // Check if the subarray length is at least 2
            } else {
                remainderMap[sum] = i;
            }
        }
        return false;
    }
};
