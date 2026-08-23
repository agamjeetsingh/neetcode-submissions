class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        vector<int> freq_1(26);
        vector<int> freq_2(26);

        int size = 0;

        for (int i = 0; i < s1.length(); i++) {
            freq_1[s1[i] - 'a']++;
        }

        for (int i = 0; i < s2.length(); i++) {
            freq_2[s2[i] - 'a']++;
            size++;

            if (size > s1.size()) {
                freq_2[s2[i - s1.size()] - 'a']--;
                size--;
            }
            
            if (freq_1 == freq_2) return true;
        }

        return false;
    }
};
