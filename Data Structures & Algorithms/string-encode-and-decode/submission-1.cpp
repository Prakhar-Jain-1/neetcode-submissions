class Solution {
public:

    string encode(vector<string>& strs) {
        string ret = "";
        for(string s:strs){
            int n = s.size();
            ret+=(n/100 + '0');
            n%=100;
            ret+=(n/10 + '0');
            ret+=(n%10 + '0');
            ret+='#';
            for(char c:s) ret+=c;
        }
        return ret;
    }

    vector<string> decode(string s) {
        if(s=="")return {};
        vector<string> ret = {};
        // cerr<<s<<endl;
        int k = 0;
        string p = "";
        k = (s[0]-'0')*100 + (s[1]-'0')*10 + s[2]-'0';
            // p = "";
            // continue;
        // cerr<<k<<" ";
        for(int i = 4; i < s.size(); i++){
            if(k == 0){
                k = (s[i++]-'0')*100 + (s[i++]-'0')*10 + s[i++]-'0';
                // cerr<<k<<" ";
                ret.push_back(p);
                p = "";
                continue;
            }
            k--;
            p+=s[i];
        }
        ret.push_back(p);
        return ret;
    }
};
