class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1); // dp[i] we are fine up to size i
        dp[0] = true;

        for (int i = 1; i <= s.size(); i++) {
            for (const string& word: wordDict) {
                if (word.size() > i) continue;
                if (dp[i - word.size()] && s.substr(i - word.size(), word.size()) == word) {
                    dp[i] = true; break;
                }
            }
        }

        return dp.back();
    }
};
