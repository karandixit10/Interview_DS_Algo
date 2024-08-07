class Solution {
private:
    const vector<string> belowTen = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
    const vector<string> belowTwenty = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
    const vector<string> belowHundred = { "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
    string solve(int num) {
        if (num < 10) {
            return belowTen[num];
        }
        if (num < 20) {
            return belowTwenty[num - 10];
        }
        if (num < 100) { // 89 = "Eighty Nine"
            return belowHundred[num / 10] + (num % 10 ? " " + solve(num % 10) : "");
        }
        if (num < 1000) { // 879 = "Eight Hundred Seventy Nine"
            return solve(num / 100) + " Hundred" +
                   (num % 100 ? " " + solve(num % 100) : "");
        }
        if (num < 1000000) { // 78579 = "Seventy Eight Thousand Five Hundred
                             // Seventy Nine"
            return solve(num / 1000) + " Thousand" +
                   (num % 1000 ? " " + solve(num % 1000) : "");
        }
        if (num < 1000000000) {
            return solve(num / 1000000) + " Million" +
                   (num % 1000000 ? " " + solve(num % 1000000) : "");
        }
        return solve(num / 1000000000) + " Billion" +
               (num % 1000000000 ? " " + solve(num % 1000000000) : "");
    }

public:
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        return solve(num);
    }
};