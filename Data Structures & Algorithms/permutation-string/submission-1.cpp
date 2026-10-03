class Solution {
public:
    bool checkInclusion(string s1, string s) {
        int n = s.size(), m = s1.size();
        if(m>n) return 0;
        int a[26] = {0};
        int e = 'a';
        for(char c:s1){
            a[c-e]++;
        }

        int l=0,r=0;
        while(l<=r and r <n){
            if(a[s[r]-e] == 0){
                for(; l<r and a[s[r]-e] == 0;l++){
                    a[s[l]-e]++;
                }
                if(a[s[r]-e]==1){
                    a[s[r]-e]--;        
                }
                else{
                    l = r+1;
                }
                r++;
                continue;
            }
            a[s[r]-e]--;
            if(r-l+1 == m){
                cerr<<l<<" "<<r;
                return 1;
            } 
                
            r++;
        }
        return 0;
    }
};
