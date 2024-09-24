class Solution {
private:
    int countDigit(int n) {
        return static_cast<int>(log10(n) + 1);
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        int ans = 0;
        for (int val : arr1) {
            while (!st.count(val) && val > 0) {
                st.insert(val);
                val /= 10;
            }
        }

        for (int val : arr2) {
            while (!st.count(val) && val > 0) {
                cout<<val<<endl;
                val /= 10;
            }
            if (val > 0) {
                ans = max(ans, countDigit(val));
            }
        }
        return ans;
    }
};