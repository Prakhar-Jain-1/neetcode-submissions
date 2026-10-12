class KthLargest {
    priority_queue<int, vector<int>, greater<int>> p;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        for(int i:nums){
            this->p.push(i);
            if(this->p.size() > k) this->p.pop();
        }
        // while()
        this->k = k;
    }
    
    int add(int val) {
        p.push(val);
        if(this->p.size() > this->k) this->p.pop();
        return p.top();
    }
};
