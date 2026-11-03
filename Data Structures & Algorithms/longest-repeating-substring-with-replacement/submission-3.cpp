class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        vector<int> freq(26);

        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            freq[s[r] - 'A']++;
            while (!isValid(freq, k)) freq[s[l++] - 'A']--;

            res = max(res, r - l + 1);
        }

        return res;
    }

    bool isValid(const vector<int>& freq, int k) {
        int most_freq = *max_element(freq.begin(), freq.end());
        int sum = 0;
        
        for (int f: freq) sum += f;

        return most_freq + k >= sum;
    }
};
