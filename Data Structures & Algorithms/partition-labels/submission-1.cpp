class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last_occurence;
        for (int i = 0; i < s.size(); i++) last_occurence[s[i]] = i;
        vector<int> res;
        int start = -1;
        int upto = 0;

        for (int i = 0; i < s.size(); i++) {
            upto = max(upto, last_occurence[s[i]]);
            if (upto == i) {
                res.push_back(i - start);
                start = i;
            }
        }

        return res;
    }
};
