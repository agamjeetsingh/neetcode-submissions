class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> freq_1(26);
        vector<int> freq_2(26);

        for (char c: s1) freq_1[c - 'a']++;

        for (int i = 0; i < s1.size(); i++) freq_2[s2[i] - 'a']++;

        if (freq_1 == freq_2) return true;

        for (int i = s1.size(); i < s2.size(); i++) {
            freq_2[s2[i] - 'a']++;
            freq_2[s2[i - s1.size()] - 'a']--;
            
            if (freq_1 == freq_2) return true;
        }

        return false;
    }
};
