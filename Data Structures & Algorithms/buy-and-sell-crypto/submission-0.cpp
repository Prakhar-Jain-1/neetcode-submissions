class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        int b = 0, s = 0;
        vector<int> pr(n+2);
        pr[0] = 101, pr[n+1] = -1;
        for(int i = 0; i < n;i++){
            pr[i+1] = p[i];
        }
        int ans = 0;
        for(int i = 1; i<=n;i++){
            for(int j = i+1; j <= n; j++){
                ans=max(pr[j]-pr[i], ans);
            }
        }
        return ans;
    }
};
