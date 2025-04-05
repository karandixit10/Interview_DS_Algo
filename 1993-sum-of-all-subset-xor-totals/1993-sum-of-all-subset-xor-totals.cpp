class Solution {
private:
    int backTrack(vector<int>& nums, int i , int xorTotal){
        
        if(i == nums.size()){
            return xorTotal;
        }
        //Pick
        int pick = backTrack(nums, i + 1, xorTotal ^ nums[i]);
        //No-Pick
        int no_pick = backTrack(nums, i+1, xorTotal);

        return pick + no_pick;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        return backTrack(nums, 0, 0);
    }
};