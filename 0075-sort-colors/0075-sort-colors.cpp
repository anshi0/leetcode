class Solution {
public:
    void sortColors(vector<int>& nums) {
    for (int i = 0; i < nums.size()-1; i++) {
    int mini = i;
    for (int j = i + 1; j < nums.size(); j++) {
      if (nums[j] < nums[mini]) {
        mini = j;
      }
    }
    int temp = nums[mini];
    nums[mini] = nums[i];
    nums[i] = temp;
  }
    }
};