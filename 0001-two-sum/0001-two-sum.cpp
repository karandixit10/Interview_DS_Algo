class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        // Build the hash table
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }

        for(int i = 0 ; i < nums.size(); i++){
            int complement = target - nums[i];
            if (mp.find(complement) != mp.end() && mp[complement] != i) {
                cout<<complement;
                return {mp[complement], i};
            }
        }
        return {};
    }
};