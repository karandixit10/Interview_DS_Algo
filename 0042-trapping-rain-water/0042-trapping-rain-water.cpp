class Solution {
public:
    int trap(vector<int>& height) {
        //O(1) solution
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int ans = 0;
        int left_max = height[left];
        int right_max = height[right];
        while(left <= right){
            if(height[left] <= height[right]){
                left_max = max(left_max, height[left]);
                ans += left_max - height[left];
                left++;
            }else{
                right_max = max(right_max, height[right]);
                ans += right_max - height[right];
                right--; 
            }
        }
        return ans;
    }
};