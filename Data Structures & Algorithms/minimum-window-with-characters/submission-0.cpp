class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq;

        string res;

        for (char c : t) {
            freq[c]++;
        }

        int l = 0;

        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            if (!freq.contains(c)) continue;

            freq[c]--;
            if (isValid(freq)) {
                while (l < r && isValid(freq)) {
                    if (!freq.contains(s[l])) {
                        l++; continue;
                    }
                    if (freq[s[l]] == 0) break;
                    freq[s[l++]]++;
                }

                if (res.length() == 0 || res.length() > (r - l + 1)) {
                    res = s.substr(l, r - l + 1);
                }
            }
            
        }

        return res;
    }

    bool isValid(unordered_map<char, int>& freq) {
        for (auto [_, f] : freq) {
            if (f > 0) return false;
        }
        return true;
    }
};
