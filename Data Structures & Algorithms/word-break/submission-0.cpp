class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()); // dp[i] = is it possible upto and including index i?

        for (int i = 0; i < s.size(); i++) {
            for (string& word: wordDict) {
                if (i + 1 >= word.size() && s.substr(i + 1 - word.size(), word.size()) == word && (i + 1 - word.size() == 0 || dp[i - word.size()])) {
                    dp[i] = true;
                }
            }
        }

        return dp.back();
    }
};
