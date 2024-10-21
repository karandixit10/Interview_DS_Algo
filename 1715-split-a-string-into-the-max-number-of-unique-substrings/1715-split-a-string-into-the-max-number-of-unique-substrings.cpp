class Solution {
private:
    unordered_set<string> set;
    int ans = 0;
    void backTrack(int ind, string &s){
        if(ind >= s.size()){
            ans = max(ans, (int)set.size());
            return;
        }
        string temp = "";
        for(int i = ind; i < s.size(); i++){
            temp += s[i];
            if(set.find(temp) == set.end()){
                set.insert(temp);
                backTrack(i+1, s);
                set.erase(temp);
            }
        }
    }
public:
    int maxUniqueSplit(string s) {
        backTrack(0,s);
        return ans;
    }
};