class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;

        for (string& str : strs) {
            vector<int> freq(26);
            for (char c : str) {
                freq[c - 'a']++;
            }
            string s;
            for (int num : freq) {
                s += num;
                s += ".";
            }

            mp[s].push_back(str);
        }

        for (auto& [_, strings]: mp) {
            res.push_back(strings);
        }

        return res;
    }
};
