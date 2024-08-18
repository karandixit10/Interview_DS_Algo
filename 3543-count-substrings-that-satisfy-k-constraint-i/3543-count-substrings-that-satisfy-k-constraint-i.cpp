class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int a = 0, b = 0;
            for (int j = i; j < s.size(); j++) {
                if (s[j] == '0')
                    a++;
                else
                    b++;
                if (a <= k || b <= k)
                    ans++;
            }
        }
        return ans;
    }
};