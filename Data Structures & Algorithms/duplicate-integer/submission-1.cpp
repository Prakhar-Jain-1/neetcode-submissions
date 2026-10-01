class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int> m;

        for (int i : nums) {
            m[i]++;
            if (m[i] == 2) {
                return true;
            }
        }

        return false;
    }
};