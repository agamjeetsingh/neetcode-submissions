class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());

        vector<vector<int>> dp(amount + 1, vector<int>(coins.size()));

        for (int j = 0; j < coins.size(); j++) {
            dp[0][j] = 1;
        }
        for (int i = 0; i <= amount; i++) {
            dp[i][0] = (i % coins[0] == 0) ? 1 : 0;
        }

        for (int i = 1; i <= amount; i++) {
            for (int j = 1; j < coins.size(); j++) {                
                for (int sum = 0; i >= sum; sum += coins[j]) {
                    dp[i][j] += dp[i - sum][j - 1];
                }
            }
        }

        return dp.back().back();
    }
};
