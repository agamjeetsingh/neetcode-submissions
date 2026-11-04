class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // vector<int> dp(cost.size() + 1);
        int c1 = 0;
        int c2 = 0;

        for (int i = 2; i <= cost.size(); i++) {
            int temp = c2;
            c2 = min(cost[i - 2] + c1, cost[i - 1] + c2);
            c1 = temp;
            // dp[i] = min(cost[i - 2] + dp[i - 2], cost[i - 1] + dp[i - 1]);
        }

        return c2;
    }
};
