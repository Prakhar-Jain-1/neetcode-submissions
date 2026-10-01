class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int>m;
        for(int i =0; i < nums.size(); i++){
            if(m[nums[i]] == 0){
                m[nums[i]] = i+1;
                if(nums[i]*2==target) continue;
            }
            if(m[target - nums[i]] != 0){
                return {m[target - nums[i]]-1, i};
            }
        }
        return {};
    }
};
