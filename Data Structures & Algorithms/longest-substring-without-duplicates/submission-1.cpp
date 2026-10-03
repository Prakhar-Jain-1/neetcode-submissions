class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int r =0, l =0;
        int alp[256] = {0};
        int ans = 0;
        bool d=0;
        while(l<=r and r<n){
            if(d){
                // cerr<<l<<" "<<r<<endl;
                alp[s[l]]--;
                if(alp[s[l]] == 1)d=0,r++;
                l++;
                continue;
            }
            alp[s[r]]++;
            if(alp[s[r]] == 2)d=1;
            else{ans = max(ans, r-l+1); r++;}
        }
        return ans;
    }
};
