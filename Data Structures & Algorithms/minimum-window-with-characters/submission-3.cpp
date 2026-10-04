class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.size() < t.size()) return "";

        vector<int> target(128, 0);
        for (char c : t) {
            target[c]++;
        }

        int required = t.size(); // Total characters needed
        int l = 0, r = 0;
        int min_len = INT_MAX;
        int start_idx = 0;

        while (r < s.size()) {
            // Expand window
            if (target[s[r]] > 0) {
                required--;
            }
            target[s[r]]--;
            r++;

            // Shrink window when all target characters are matched
            while (required == 0) {
                if (r - l < min_len) {
                    min_len = r - l;
                    start_idx = l;
                }

                target[s[l]]++;
                if (target[s[l]] > 0) {
                    required++; // We lost a required character
                }
                l++;
            }
        }

        return min_len == INT_MAX ? "" : s.substr(start_idx, min_len);
    }
};