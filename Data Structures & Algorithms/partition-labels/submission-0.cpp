class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;

        unordered_map<char, int> lastOccurence;
        for (int i = 0; i < s.size(); i++) {
            lastOccurence[s[i]] = i;
        }

        int start = 0;
        unordered_set<char> bad;

        for (int i = 0; i < s.size(); i++) {
            bad.insert(s[i]);
            if (lastOccurence[s[i]] == i) bad.erase(s[i]);
            if (bad.empty()) {
                res.push_back(i + 1 - start);
                start = i + 1;
            }
        }

        return res;
    }
};
