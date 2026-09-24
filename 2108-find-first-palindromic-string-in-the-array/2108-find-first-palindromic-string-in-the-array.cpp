class Solution {
public:
    string firstPalindrome(vector<string>& words) {

        for(int i=0;i<words.size();i++){
            string str = words[i];
            int st=0;
            int end = str.size()-1;

            while(st<end){
                if(str[st] != str[end]){
                    break;
                }

                st++;
                end--;
            }

            if(st >= end){
                return str;
            }

        }

        return "";
        
    }
};