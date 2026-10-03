class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        if(n<3) return 0;
        int i = 0, j = n-1, ans = 0;
        int mn,r;
        if(h[0]<h[n-1]){
            mn = h[0];
            i++;
            r = 0;
        }
        else{
            mn = h[n-1];
            j--;
            r = 1;
        }
        while(i<j){
            if(r == 0){
                if(h[i]>mn){
                    if(h[j]>h[i]){
                        mn = h[i];
                        r = 0;
                        i++;
                    }
                    else{
                        mn = h[j];
                        r = 1;
                        j--;
                    }
                }
                else{
                    ans+=mn-h[i];
                    i++;
                }
                continue;
            }
            if(h[j]>mn){
                if(h[j]>h[i]){
                    mn = h[i];
                    r = 0;
                    i++;
                }
                else{
                    mn = h[j];
                    r = 1;
                    j--;
                }
            }
            else{
                ans+=mn-h[j];
                j--;
            }
        }
        return ans;
    }
};
