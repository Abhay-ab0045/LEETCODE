class Solution {
public:
    set<string> parse(string &s, int &i) {
        set<string> ans;

        while(i < s.size() && s[i] != '}') {
            set<string> cur;

            if(s[i] == '{') {
                i++;
                cur = parse(s, i);
                i++;
            }
            else {
                cur.insert(string(1, s[i]));
                i++;
            }

            if(ans.empty()) {
                ans = cur;
            }
            else {
                set<string> temp;
                for(string a : ans) {
                    for(string b : cur) {
                        temp.insert(a + b);
                    }
                }
                ans = temp;
            }

            if(i < s.size() && s[i] == ',') {
                i++;
                for(auto x : parse(s, i)) {
                    ans.insert(x);
                }
            }
        }

        return ans;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> ans = parse(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};