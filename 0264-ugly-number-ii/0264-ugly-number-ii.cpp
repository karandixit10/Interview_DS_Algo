class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(1691, 0);
        dp[0] = 1;
        int iMulti2 = 0, iMulti3 = 0, iMulti5 = 0;
        int nextMulti2 = 2, nextMulti3 = 3, nextMulti5 = 5;
        for (int i = 1; i < n; i++) {
            int nextUgly = min({nextMulti2,nextMulti3,nextMulti5});
            dp[i] = nextUgly;
            if(nextUgly == nextMulti2){
                iMulti2++;
                nextMulti2 = dp[iMulti2] * 2;
            }
            if (nextUgly == nextMulti3){
                iMulti3++;
                nextMulti3 = dp[iMulti3] * 3;
            }
            if (nextUgly == nextMulti5){
                iMulti5++;
                nextMulti5 = dp[iMulti5] * 5;
            }
        }
        return dp[n-1];
    }
};