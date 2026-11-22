class Solution {
public:
    bool checkString(const string& s) {
        return is_sorted(s.begin(), s.end());
    }
};