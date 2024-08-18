class Solution {
public:
    typedef long long ll;
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
        for(int i = 1 ; i <= n; i++) {
            dp[i][0] = max(dp[i][0], dp[i-1][0] + (ll) (energyDrinkA[i-1])); // take A
            dp[i][1] = max(dp[i][1], dp[i-1][1] + (ll) (energyDrinkB[i-1])); // take B

            dp[i][0] = max(dp[i][0], dp[i-1][1]); // not taking A;
            dp[i][1] = max(dp[i][1], dp[i-1][0]); // not taking B;
        }
        return max(dp[n][0], dp[n][1]);
    }
};