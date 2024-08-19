class Solution {
private:
    int solve(int currCountA, int pasteCountA, int n, vector<vector<int>>& dp) {
        if(currCountA == n) {
            return 0;
        }
        if(currCountA > n) {
            return 1000;
        }
        if(dp[currCountA][pasteCountA] != -1) {
            return dp[currCountA][pasteCountA];
        }
        int copyPaste = 1 + 1 + solve(currCountA + currCountA, currCountA, n, dp);
        int paste     = 1 + solve(currCountA + pasteCountA, pasteCountA, n, dp);

        return dp[currCountA][pasteCountA] = min(copyPaste, paste);
    }
public:
    int minSteps(int n) {
        if(n == 1)
            return 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return 1 + solve(1, 1, n, dp);
    }
};