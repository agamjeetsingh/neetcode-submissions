class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;

        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            while (!isValid(s, k, l, r + 1)) l++;

            res = max(res, r - l + 1);
        }

        return res;
    }

    bool isValid(const string& s, int k, int start, int end) {
        vector<int> freq(26);

        for (int i = start; i < end; i++) freq[s[i] - 'A']++;

        int most_freq = *max_element(freq.begin(), freq.end());

        return most_freq + k >= end - start;
    }
};
