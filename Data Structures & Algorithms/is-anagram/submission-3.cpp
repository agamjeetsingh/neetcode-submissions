class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq_s(26);
        vector<int> freq_t(26);

        for (char c: s) freq_s[c - 'a']++;
        for (char c: t) freq_t[c - 'a']++;

        return freq_s == freq_t;
    }
};
