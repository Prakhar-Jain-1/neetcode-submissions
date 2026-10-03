#define A 'A'
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int r =0, l =0;
        int alp[26] = {0};
        int ans = 0;
        while(l<=r and r<n){
            alp[s[r]-A]++;
            int m = *max_element(alp, alp + 26);
            while(m+k<r-l+1){
                alp[s[l]-A]--;
                m = *max_element(alp, alp+26);
                l++;
            }
            ans = max(r-l+1, ans);
            r++;
        }
        return ans;
    }
};
