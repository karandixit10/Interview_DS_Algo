class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long int ans = 0;
        priority_queue<int> pq;
        for (auto& i : nums) {
            pq.push(i);
        }

        while(k--) {
            int maxi = pq.top();
            ans += maxi;
            pq.pop();
            pq.push(ceil(maxi/3.0));
        }
        return ans;
    }
};