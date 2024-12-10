class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefixSum(n,0);

        for(int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i-1];
            if(nums[i]%2 == nums[i-1]%2)
                prefixSum[i]++;
        }
        int qn = queries.size();
        vector<bool> result(qn, true);
        if(n == 1) return result;

        for (int i = 0; i < qn; i++) {
            int from = queries[i][0];
            int to = queries[i][1];
            int count = prefixSum[to] - prefixSum[from];
            result[i] = (count>=1) ? false : true;
        }
        
        return result;
        
    }
};