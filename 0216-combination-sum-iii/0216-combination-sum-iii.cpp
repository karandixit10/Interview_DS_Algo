class Solution {
private:
    void backTrack(int ind, int k, int n, vector<vector<int>>& result, vector<int> &curr){
        if(n < 0 || curr.size() > k) return;
        if(n == 0 && curr.size() == k) {
            result.push_back(curr);
            return;
        }
        for(int i = ind; i <= 9; i++){
            curr.push_back(i);
            backTrack(i+1, k, n - i,result, curr);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> curr;
        backTrack(1, k , n , result, curr);
        return result;
    }
};