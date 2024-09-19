class Solution {
private:
    vector<int> memoization(string& expression, vector<vector<vector<int>>>& dp,
                            int start, int end) {
        vector<int> results;
        if (!dp[start][end].empty()) {
            return dp[start][end];
        }

        if (start == end) {
            results.push_back(expression[start] - '0');
            return results;
        }
        if (end - start == 1 && isdigit(expression[start])) {
            int tens = expression[start] - '0';
            int ones = expression[end] - '0';
            results.push_back(10 * tens + ones);
            return results;
        }

        for (int i = start; i <= end; i++) {
            char currentChar = expression[i];
            if (isdigit(currentChar)) {
                continue;
            }
            vector<int> leftResults  = memoization(expression, dp, start, i - 1);
            vector<int> rightResults = memoization(expression, dp, i + 1, end);
            for (int leftValue : leftResults) {
                for (int rightValue : rightResults) {
                    switch (currentChar) {
                    case '+':
                        results.push_back(leftValue + rightValue);
                        break;
                    case '-':
                        results.push_back(leftValue - rightValue);
                        break;
                    case '*':
                        results.push_back(leftValue * rightValue);
                        break;
                    }
                }
            }
        }
        return dp[start][end] = results;
    }

public:
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n));
        return memoization(expression, dp, 0, expression.length() - 1);
    }
};