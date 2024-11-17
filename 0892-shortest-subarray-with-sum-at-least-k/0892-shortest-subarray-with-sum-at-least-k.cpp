class Solution {
public:
    int shortestSubarray(vector<int>& nums, int K) {
        int N = nums.size();

        deque<int> deq;
        vector<long long> cumulativeSum(N, 0);

        int result = INT_MAX;
        int j = 0;
        // Compute cumulative sum in the cumulativeSum array using while loop
        while (j < N) {
            if (j == 0)
                cumulativeSum[j] = nums[j];
            else
                cumulativeSum[j] = cumulativeSum[j - 1] + nums[j];

            if (cumulativeSum[j] >= K)
                result = min(result, j + 1);

            while (!deq.empty() &&
                   cumulativeSum[j] - cumulativeSum[deq.front()] >= K) {
                result = min(result, j - deq.front());
                deq.pop_front();
            }

            while (!deq.empty() &&
                   cumulativeSum[j] <= cumulativeSum[deq.back()]) {
                deq.pop_back(); 
            }

            deq.push_back(j);

            j++; 
        }

        // Return the result if we found a valid subarray, otherwise return -1
        return result == INT_MAX ? -1 : result;
    }
};
