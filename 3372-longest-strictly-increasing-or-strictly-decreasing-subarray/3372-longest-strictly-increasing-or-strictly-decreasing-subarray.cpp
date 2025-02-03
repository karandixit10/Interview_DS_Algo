class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxLength = 1;
        int currentLength = 1;
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                currentLength++;
            } else {
                maxLength = max(maxLength, currentLength);
                currentLength = 1;
            }
        }
        maxLength = max(maxLength, currentLength);
        currentLength = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) {
                currentLength++;
            } else {
                maxLength = max(maxLength, currentLength);
                currentLength = 1;
            }
        }
        maxLength = max(maxLength, currentLength);

        return maxLength;
    }
};