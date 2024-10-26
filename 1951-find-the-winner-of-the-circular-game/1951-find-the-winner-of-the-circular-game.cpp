class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> circle;
        for (int i = 1; i <= n; i++) {
            circle.push_back(i);
        }
        int i = 0;
        while(circle.size() > 1) {
            int idx = (i + k - 1) % circle.size();
            circle.erase(circle.begin() + idx);
            i = idx;
        }
        return circle.front();
    }
};