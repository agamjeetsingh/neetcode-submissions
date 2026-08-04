class Solution {
public:
    bool isPalindrome(string s) {
        erase_if(s, [](char c) {
            return !isalnum(c);
        });
        transform(s.begin(), s.end(), s.begin(), [](char c) {
            return tolower(c);
        });
        int n = s.length();
        cout << s << endl;
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1]) return false;
        }
        return true;
    }
};
