class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        vector<vector<string>> res;

        for (const string& str: strs) {
            vector<int> freq(26);

            for (char c: str) freq[c - 'a']++;

            string s;
            
            for (int i = 0; i < 26; i++) {
                s += to_string(freq[i]);
                s += ",";
            }

            mp[s].push_back(str);
        }

        for (auto& [_, vec]: mp) {
            res.push_back(vec);
        }

        return res;
    }
};
