class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for (string str : strs) {
            res += to_string(str.length());
            res += "#";
            res += str;
        }
        cout << res << endl;
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;

        stringstream ss(s);

        int len = 0;
        
        while (ss >> len) {
            ss.ignore();
            string str;
            str.resize(len);
            ss.read(&str[0], len);
            res.push_back(str);
        }

        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
