class Solution {
private:
    void backTrack(vector<int>& candidates, int target, int sum, int ind,
                   vector<int>& curr, vector<vector<int>>& result) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            result.push_back(curr);
            return;
        }
        for (int i = ind; i < candidates.size(); i++) {
            if (i > ind && candidates[i] == candidates[i - 1]) {
                continue;
            }
            curr.push_back(candidates[i]);
            backTrack(candidates, target, sum + candidates[i], i + 1, curr,
                      result);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> curr;
        vector<vector<int>> res;
        backTrack(candidates, target, 0, 0, curr, res);
        return res;
    }
};