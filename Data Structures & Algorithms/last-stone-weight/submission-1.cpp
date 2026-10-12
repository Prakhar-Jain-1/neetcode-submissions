class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> p(stones.begin(), stones.end());
        while(p.size()>1){
            int i = p.top();
            p.pop();
            int j = p.top();
            p.pop();
            if(i == j) continue;
            p.push(abs(i-j));
        }
        if(p.empty()) return 0;
        return p.top();
    }
};
