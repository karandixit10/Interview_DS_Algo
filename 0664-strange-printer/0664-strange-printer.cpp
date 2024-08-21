class Solution {
private:
    string removeConsecutive(string& s){
        string unique;
        int i = 0;
        while(i < s.size()){
            char curr = s[i];
            unique += curr;
            while(i < s.size() && s[i] == curr){
                i++;
            }
        }
        return unique;
    }
    int memoization(int start, int end, string &s, vector<vector<int>> &dp){
        if(start > end){
            return 0;
        }
        if(dp[start][end] != -1) return dp[start][end];

        int printAll = 1 + memoization(start+1, end, s, dp);

        for(int k = start+1; k <= end; k++){
            if(s[k] == s[start]){
                int printMatching = memoization(start, k-1, s, dp) + memoization(k+1, end, s, dp);
                printAll = min(printAll, printMatching);
            }
        }
        return dp[start][end] = printAll;
    }
public:
    int strangePrinter(string s) {
        s = removeConsecutive(s);
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return memoization(0, n - 1, s, dp);
    }
};