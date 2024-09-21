class Solution {
private:
    void dfs(int currentNumber, int limit, vector<int>& ans) {
        if(currentNumber > limit) return;

        ans.push_back(currentNumber);

        for (int nextDigit = 0; nextDigit <= 9; nextDigit++) {
            int nextNumber = currentNumber * 10 + nextDigit;
            if(nextNumber <= limit) {
                dfs(nextNumber, limit, ans);
            } else {
                break;
            }
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for (int start = 1; start <= 9; start++) {
            dfs(start, n, ans);
        }
        return ans;
    }
};