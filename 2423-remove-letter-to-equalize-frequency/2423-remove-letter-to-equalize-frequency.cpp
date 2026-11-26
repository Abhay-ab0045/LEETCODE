class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> freq(26, 0);

        for(char ch : word) {
            freq[ch - 'a']++;
        }

        for(int i = 0; i < 26; i++) {
            if(freq[i] == 0) continue;

            freq[i]--;

            int count = 0;
            bool flag = true;

            for(int j = 0; j < 26; j++) {
                if(freq[j] == 0) continue;

                if(count == 0) {
                    count = freq[j];
                }
                else if(freq[j] != count) {
                    flag = false;
                    break;
                }
            }

            if(flag) return true;

            freq[i]++;
        }

        return false;
    }
};