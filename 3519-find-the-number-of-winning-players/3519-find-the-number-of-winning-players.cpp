class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        unordered_map<int,unordered_map<int,int>>mp;
        for(auto& it: pick){
            int player = it[0];
            int ball = it[1];
            mp[player][ball]++;
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(auto& temp : mp[i]){
                int freq = temp.second;
                if(freq > i){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};