class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        unordered_set<char> st;
        for(int i = 0 ; i < allowed.size(); i++) {
            st.insert(allowed[i]);
        }
        for(string &word : words) {
            bool isConsistent = true;

            for(int i = 0 ; i < word.size(); i++) {
                if(st.find(word[i]) == st.end()) {
                    isConsistent = false;
                    break;
                }
            }
            if(isConsistent) {
                ans++;
            }
        }
        return ans;
    }
};