class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        for(int i = 0 ; i < nums.size(); i++) {
            if(st.empty() || nums[st.top()] > nums[i]) {
                st.push(i);
            }
        }

        int res = 0; 

        for(int j = nums.size() - 1; j >=0 ;j--) {
            while(!st.empty() && nums[st.top()] <= nums[j]) {
                res = max(res, j - st.top());
                st.pop();
            }
        }
        return res;
    }
};