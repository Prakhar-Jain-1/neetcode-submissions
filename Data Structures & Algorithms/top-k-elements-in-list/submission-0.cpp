class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        pair<int,int> f[2001] = {{0,0}};
        for(int i =0;i<2001;i++){
            f[i].second = i-1000;
        }
        for(int i:nums){
            f[i+1000].first++;
        }
        sort(f, f+2001);
        vector<int> ret;
        for(int i = 2000; i > 2000-k;i--){
            ret.push_back(f[i].second);
        }
        return ret;
    }
};
