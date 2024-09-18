class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numString;
        for(int num : nums) {
            numString.push_back(to_string(num));
        }

        sort(numString.begin(), numString.end(), [](string &a, string&b) {
            return a + b > b + a;
        });

        if(numString[0] == "0") return "0";

        string ans;

        for(string &str : numString) {
            ans += str;
        }

        return ans;
 
    }
};