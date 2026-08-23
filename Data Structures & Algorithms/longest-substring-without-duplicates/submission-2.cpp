class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;

        int res = 0;

        unordered_set<char> cs;

        for (int r = 0; r < s.length(); r++) {
            if (cs.contains(s[r])) {
                while (l <= r && cs.contains(s[r])) {
                    cs.erase(s[l++]);
                }
            }
            res = max(res, r - l + 1);

            cs.insert(s[r]);
        }

        return res;
    }
};
