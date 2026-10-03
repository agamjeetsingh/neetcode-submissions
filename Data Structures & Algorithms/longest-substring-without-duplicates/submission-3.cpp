class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;

        int l = 0;

        unordered_set<char> unique;

        for (int r = 0; r < s.length(); r++) {
            while (l < r && unique.contains(s[r])) {
                unique.erase(s[l++]);
            }
            unique.insert(s[r]);
            res = max(res, r - l + 1);
        }

        return res;
    }
};
