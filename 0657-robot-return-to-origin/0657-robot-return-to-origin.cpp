class Solution {
public:
    bool judgeCircle(string moves) {
        int U = 0, D = 0, L = 0, R = 0;

        for (char ch : moves) {
            if (ch == 'U') U++;
            else if (ch == 'D') D++;
            else if (ch == 'L') L++;
            else if (ch == 'R') R++;
        }

        return U == D && L == R;
    }
};