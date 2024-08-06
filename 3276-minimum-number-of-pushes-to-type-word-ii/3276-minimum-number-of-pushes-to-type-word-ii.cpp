class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mp(26, 0);
        for(char &ch: word)
            mp[ch - 'a']++;
    
        sort(begin(mp), end(mp), greater<int>()); 

        int ans = 0;
        for(int i = 0; i < 26; i++){
            if (mp[i] == 0) break;
            ans += (i/8 + 1) * mp[i];
        }
        return ans;
    }
};