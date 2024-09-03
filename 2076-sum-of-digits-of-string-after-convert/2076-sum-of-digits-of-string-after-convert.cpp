class Solution {
public:
    int getLucky(string s, int k) {
        string s1 = "";
        for (char ch : s) {
            s1 += to_string(ch - 'a' + 1);
        }

        while(k--) {
            int sum = 0;
            for(char ch : s1){
                sum += ch - '0';
            }
            s1 = to_string(sum);
         }
         return stoi(s1);
    }
};