class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        string ans = "";

        for (int i = 0; i < n; i++) {
            bool lower[26] = {false};
            bool upper[26] = {false};

            for (int j = i; j < n; j++) {
                if (islower(s[j]))
                    lower[s[j] - 'a'] = true;
                else
                    upper[s[j] - 'A'] = true;

                bool nice = true;

                for (int k = 0; k < 26; k++) {
                    if (lower[k] != upper[k]) {
                        nice = false;
                        break;
                    }
                }

                if (nice && j - i + 1 > ans.size()) {
                    ans = s.substr(i, j - i + 1);
                }
            }
        }

        return ans;
    }
};