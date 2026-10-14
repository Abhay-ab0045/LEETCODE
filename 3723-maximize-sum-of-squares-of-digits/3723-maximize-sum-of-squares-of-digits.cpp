class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";

        string ans;
        ans.reserve(num);

        while (sum >= 9) {
            ans += '9';
            sum -= 9;
        }

        if (ans.size() < num) {
            ans += char('0' + sum);
        }

        while (ans.size() < num) {
            ans += '0';
        }

        return ans;
    }
};