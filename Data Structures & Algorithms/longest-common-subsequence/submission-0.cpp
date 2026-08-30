class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(); int n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n));
        // dp[i][j] is longest common sequence in text1[i:], text2[j:]

        // if text1[i] == text2[j], then dp[i][j] = 1 + dp[i + 1][j + 1]
        // if not then dp[i][j] = max(dp[i][j + 1], dp[i + 1][j])

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    dp[i][j] += 1;
                    if (i + 1 <= m - 1 && j + 1 <= n - 1) {
                        dp[i][j] += dp[i + 1][j + 1];
                    }
                } else {
                    if (i + 1 <= m - 1) {
                        dp[i][j] = dp[i + 1][j];
                    }
                    if (j + 1 <= n - 1) {
                        dp[i][j] = max(dp[i][j], dp[i][j + 1]);
                    }
                }
            }
        }
        return dp[0][0];
    }
};
