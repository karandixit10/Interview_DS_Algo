class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int swaps = 0;
        for(int i = 0 ; i < s.size(); i++) {
            if(s[i] == '['){
                st.push(s[i]);
            }
            else {
                if(!st.empty()) 
                    st.pop();
                else {
                    swaps++;
                }
            }
        }
        return swaps%2 ? (swaps+1)/2 : swaps/2;
    }
};
