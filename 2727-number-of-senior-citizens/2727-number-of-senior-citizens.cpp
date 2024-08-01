class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;
        for(string &ch: details){
            int age = stoi(ch.substr(11, 2));

            if(age > 60){
                res++;
            }
        }
        return res;
    }
};