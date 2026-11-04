class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        unordered_map<char, char> mp{{')', '('}, {'}', '{'}, {']', '['}};

        for (char c: s) {
            if (!mp.contains(c)) {
                st.push(c);
            } else {
                if (!st.empty() && st.top() == mp[c]) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};
