class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(); int n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // dp[i][j] = num of distinct subsequences of s[m;] equal to t[n:]
        // if s[i] == t[j], dp[i][j] += dp[i + 1][j + 1]
        // dp[i][j] += dp[i + 1][j]
        for (int i = 0; i <= m; i++) {
            dp[i][n] = 1;
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    dp[i][j] += dp[i + 1][j + 1];
                    // if (i + 1 <= m - 1 && j + 1 <= n - 1) {
                    //     dp[i][j] += dp[i + 1][j + 1];
                    // }
                    // if (i + 1 > m - 1 && j + 1 > n - 1) {
                    //     dp[i][j] += 1;
                    // }
                    // dp[i][j] += (i + 1 <= m - 1 && j + 1 <= n - 1) ? dp[i + 1][j + 1] : 1;
                }
                // if (i + 1 <= m - 1) {
                //     dp[i][j] += dp[i + 1][j];
                // }
                dp[i][j] += dp[i + 1][j];
            }
        }

        // for (int i = 0; i <= m; i++) {
        //     for (int j = 0; j <= n; j++) {
        //         cout << "i=" << i << ", j=" << j << ", dp = " << dp[i][j] << endl;
        //     }
        // }

        return dp[0][0];
    }
};
