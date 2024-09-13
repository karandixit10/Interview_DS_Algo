class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;
        int n = arr.size();
        vector<int> cumXor(n + 1, 0);
        cumXor[0] = arr[0];

        for (int i = 1; i < n; i++) {
            cumXor[i] = cumXor[i-1] ^ arr[i];
        }

        for(auto& query : queries) { //O(q)
            int L = query[0];
            int R = query[1];

            int xor_val = cumXor[R] ^ (L == 0 ? 0 : cumXor[L-1]);

            result.push_back(xor_val);
        }

        return result;
    }
};