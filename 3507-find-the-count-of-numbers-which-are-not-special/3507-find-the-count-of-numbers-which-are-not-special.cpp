class Solution {
private:
    vector<int> sieveOfEratosthenes(int n) {
        vector<bool> is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (is_prime[i] == true) {
                for (int j = i * i; j <= n; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        vector<int> primes;
        for (int p = 2; p <= n; ++p) {
            if (is_prime[p]) {
                primes.push_back(p);
            }
        }
        return primes;
    }

public:
    int nonSpecialCount(int l, int r) {
        int special = 0;
        vector<int> primes = sieveOfEratosthenes(sqrt(r));
        for (int prime : primes) {
            int sq = prime * prime;
            if (sq >= l && sq <= r) {
                special++;
            }
        }
        int total = r - l + 1;
        return total - special;
    }
};