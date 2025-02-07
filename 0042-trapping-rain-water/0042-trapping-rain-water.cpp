class Solution {
public:
    // vector<int> prefixMax(vector<int>& height){
    //     int n = height.size();
    //     vector<int> prefix(n, 0);
    //     prefix[0] = height[0];
    //     for(int i = 1; i < n; i++){
    //         prefix[i] = max(prefix[i - 1], height[i]);
    //     }
    //     return prefix;
    // }

    // vector<int> suffixMax(vector<int>& height){
    //     int n = height.size();
    //     vector<int> suffix(n, 0);
    //     suffix[n - 1] = height[n - 1];
    //     for(int i = n - 2; i >= 0; i--){
    //         suffix[i] = max(suffix[i + 1], height[i]);
    //     }
    //     return suffix;
    // }

    int trap(vector<int>& height) {
        //if(height.empty()) return 0; // Handle empty input
        
        //optimallllll
        int n = height.size();
        int LeftMax = 0, rightMax = 0, total = 0, l=0, r= n-1;
        while(l<r){
            if(height[l] <= height[r]){
                if(LeftMax > height[l]){
                    total += LeftMax-height[l];
                }
                else LeftMax = height[l];
                l++;
            }
            else {
                if(rightMax > height[r]){
                    total += rightMax - height[r];
                }
                else rightMax = height[r];
                r--;
            }
        }

        // int n = height.size();
        // vector<int> leftMax = prefixMax(height);  // Store prefix max values
        // vector<int> rightMax = suffixMax(height); // Store suffix max values

        // int total = 0;
        // for(int i = 0; i < n; i++){
        //     if(height[i] < leftMax[i] && height[i] < rightMax[i]){
        //         total += min(leftMax[i], rightMax[i]) - height[i]; 
        //     }
        // }
        return total;
    }
};
