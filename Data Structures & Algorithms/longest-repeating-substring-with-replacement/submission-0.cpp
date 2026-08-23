class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26);

        int l = 0;
        int res = 0;

        for (int r = 0; r < s.length(); r++) {
            freq[s[r] - 'A']++;

            while (l < r && !isValid(freq, k)) {
                freq[s[l++] - 'A']--;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }

    bool isValid(vector<int>& freq, int k) {
        int max_index = distance(freq.begin(), max_element(freq.begin(), freq.end()));

        int bad = 0;

        for (int i = 0; i < 26; i++) {
            if (i == max_index) continue;

            bad += freq[i];
            if (bad > k) return false;
        }
        return true;
    }
};
