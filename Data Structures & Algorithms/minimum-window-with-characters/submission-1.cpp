class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq;

        for (char c: t) freq[c]--;

        int l = 0;
        string_view res;
        int min_length = INT_MAX;

        for (int r = 0; r < s.size(); r++) {
            freq[s[r]]++;

            while (freq[s[l]] > 0) freq[s[l++]]--;

            bool valid = true;
            for (auto [_, f]: freq) {
                if (f < 0) {
                    valid = false;
                    break;
                }
            }

            if (valid && r - l + 1 < min_length) {
                min_length = r - l + 1;
                res = string_view{s}.substr(l, r - l + 1);
            }
        }

        return string{res};
    }
};
