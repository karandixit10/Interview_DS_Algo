class Solution {
private:
    int solve(int i, string& s, unordered_set<string>& st, vector<int>& dp) {
        if (i >= s.size()) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int result = 1 + solve(i + 1, s, st, dp);

        for (int j = i; j < s.size(); j++) {
            string curr = s.substr(i, j-i+1);
            if (st.count(curr)) {
                result = min(result, solve(j + 1, s, st, dp));
            }
        }
        return dp[i] = result;
    }

public:
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> dp(51, -1);
        unordered_set<string> st(begin(dictionary), end(dictionary));

        return solve(0, s, st, dp);
    }
};