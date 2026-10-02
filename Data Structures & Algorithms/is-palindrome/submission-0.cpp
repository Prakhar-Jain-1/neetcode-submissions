class Solution {
public:
    bool isPalindrome(string t) {
        string s = "";
        for(char c:t){
            if(c>='a' and c<='z'){
                s+=c;
            }
            if(c>='A' and c<='Z'){
                s+=(c-'A'+'a');
            }
            if(c>='0' and c<='9') s+=c;
        }
        int i = 0, j = s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return 0;
            i++,j--;
        }
        return 1;
    }
};
