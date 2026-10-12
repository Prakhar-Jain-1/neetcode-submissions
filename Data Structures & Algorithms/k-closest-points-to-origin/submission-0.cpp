class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](vector<int> a, vector<int> b) {
            return (a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> p(cmp);
        for(vector<int> i:points){
            p.push(i);
            if(p.size()>k)p.pop();
        }
        vector<vector<int>> ret;
        while(p.empty() == false){
            ret.push_back(p.top());p.pop();
        }
        return ret;
    }
};
