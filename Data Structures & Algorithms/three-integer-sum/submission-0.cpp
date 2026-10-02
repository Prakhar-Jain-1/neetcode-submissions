class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int>> ret;
        for(int i = 0; i < n; i++){
            int t = -nums[i];
            int j = i+1, k = n-1;
            while(j<k){
                if(nums[j]+nums[k]<t)j++;
                else if (nums[j]+nums[k] >t)k--;
                else{
                    ret.insert({nums[i], nums[j++], nums[k--]});
                }
            }
        }

        return vector<vector<int>>(ret.begin(), ret.end());
    }
};
