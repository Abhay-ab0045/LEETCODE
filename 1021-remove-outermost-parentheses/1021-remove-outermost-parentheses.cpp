class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        string temp = "";
        int balance = 0;

        for(char ch : s) {
            temp += ch;

            if(ch == '(')
                balance++;
            else
                balance--;

            if(balance == 0) {
                ans += temp.substr(1, temp.size() - 2);
                temp = "";
            }
        }

        return ans;
    }
};