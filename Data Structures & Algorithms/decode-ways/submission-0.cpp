class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size());
        // dp[i] = number of ways for s[i:]
        // dp[i] = dp[i + 1] + (if two letters make sense then dp[i + 2])       
        if (s.size() == 1) {
            return makesSense(s) ? 1 : 0;
        }
        dp[s.size() - 1] = makesSense(s.substr(s.size() - 1, 1)) ? 1 : 0;

        if (s.size() == 2) {
            return (makesSense(s.substr(s.size() - 2, 1)) ? dp[s.size() - 1] : 0) + (makesSense(s.substr(s.size() - 2, 2)) ? 1 : 0);
        }
        dp[s.size() - 2] = (makesSense(s.substr(s.size() - 2, 1)) ? dp[s.size() - 1] : 0) + (makesSense(s.substr(s.size() - 2, 2)) ? 1 : 0);

        for (int i = s.size() - 3; i >= 0; i--) {
            // cout << dp[2] << endl;
            // cout << dp[1];

            dp[i] = (makesSense(s.substr(i, 1)) ? dp[i + 1] : 0) + (makesSense(s.substr(i, 2)) ? dp[i + 2] : 0);
        }

        return dp[0];
    }

    bool makesSense(string s) {
        return 1 <= stoi(s) && stoi(s) <= 26 && s[0] != '0';
    }
};
