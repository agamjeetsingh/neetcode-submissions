class Solution {
public:

    string encode(vector<string>& strs) {
        string res;

        for (const string& str: strs) {
            res += to_string(str.size());
            res += ",";
            res += str;
        }

        return res;
    }

    vector<string> decode(string s) {
        int start = 0;

        vector<string> res;

        while (start < s.size()) {
            size_t pos;
            int len = stoi(s.substr(start), &pos);
            res.push_back(s.substr(start + pos + 1, len));
            start = start + pos + 1 + len;
        }

        return res;
    }
};
