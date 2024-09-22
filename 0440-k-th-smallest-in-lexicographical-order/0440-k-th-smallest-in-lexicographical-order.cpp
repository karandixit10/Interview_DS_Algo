class Solution {
private:
    int Count(long curr,long next, int n) {
        int countNum = 0;

        while(curr <= n) {
            countNum += next - curr; //20 - 10

            curr *= 10; //10
            next *= 10; //20

            next = min(next, long(n+1)); // next should not exceed the limit; *imp
        }
        return countNum; // 11
    }
public:
    int findKthNumber(int n, int k) {
        long curr = 1; 
        k -= 1;

        while(k > 0) {
            int count = Count(curr, curr+1, n);
            if(count <= k) {
                curr++; // update to next prefix
                k -= count; //skipping the elements under curr prefix tree
            } else {
                curr *= 10; // Same tree prefix but go deeper
                k -= 1; //count decrease
            }
        }
        return curr;
    }
};