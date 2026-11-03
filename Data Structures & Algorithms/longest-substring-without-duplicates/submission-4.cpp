class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> cs(128);

        int l = 0;
        int r = 0;

        int res = 0;

        for (int r = 0; r < s.size(); r++) {
            unsigned char c = s[r];
            while (cs[c]) cs[static_cast<unsigned char>(s[l++])] = false;

            cs[c] = true;
            res = max(res, r - l + 1);
        }

        return res;
    }
};
