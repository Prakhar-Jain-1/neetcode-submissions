class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        // int b = 0, s = 0;
        vector<int> pr(n+2);
        pr[0] = 101, pr[n+1] = -1;
        for(int i = 0; i < n;i++){
            pr[i+1] = p[i];
        }
        int ans = 0, b = pr[1];
        for(int i = 2; i<=n;i++){
            ans = max(pr[i]-b, ans);
            b = min(pr[i], b);
        }
        return ans;
    }
};
