class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int n = s.length();
        unordered_map<char, int> freqs;

        int res = 0;

        while (r < n) {
            if (freqs[s[r]]++ > 0) {
                // l++ until its settled
                while (freqs[s[r]] > 1) {
                    freqs[s[l++]]--;
                }
            }
            res = max(res, r - l + 1);
            
            r++;
        }

        return res;
    }
};
