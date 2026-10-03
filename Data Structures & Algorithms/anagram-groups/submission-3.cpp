class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;

        for (auto& str: strs) {
            vector<int> freq(26);

            for (char c: str) freq[c - 'a']++;
            string hash;
            for (int num: freq) hash += to_string(num) + "#";

            mp[hash].push_back(str);
        }


        for (auto& [_, strings]: mp) {
            res.push_back(strings);
        }

        return res;
    }
};
