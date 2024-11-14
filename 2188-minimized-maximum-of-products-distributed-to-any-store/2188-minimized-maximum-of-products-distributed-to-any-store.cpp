class Solution {
private:
    bool canDistribute(int x, vector<int>& quantities, int n) {
        for(int &products : quantities) {

            n -= (products + x - 1)/ x; //Ceil
            if(n < 0) return false;
        }
        return true;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1;
        int right = *max_element(quantities.begin(), quantities.end());
        int result = 0;

        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (canDistribute(middle, quantities, n)) {
                result = middle;
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
        return result;
    }
};