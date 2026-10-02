class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,pair<int, int>> m;
        int ans =0;
        for(int i:nums){
            m[i].first = max(m[i+1].first+1, m[i].first);
            m[i].second = max(m[i-1].second+1, m[i].second);
            m[i-m[i].second+1].first = max(m[i-1].second + m[i+1].first + 1,m[i-m[i].second+1].first);
            m[i+m[i].first-1].second = max(m[i+1].first + m[i-1].second + 1,m[i+m[i].first-1].second);
            ans = max({m[i].first, ans, m[i].second,m[i+m[i].first-1].second,m[i-m[i].second+1].first});
        }
        return ans;
    }
};
