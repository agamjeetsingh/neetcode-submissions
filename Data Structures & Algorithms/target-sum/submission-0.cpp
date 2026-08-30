class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num: nums) sum += abs(num);
        vector<int> dp(2 * sum + 1);
        if (target > sum || target < -sum) return 0;
        dp[0 + sum] = 1;

        for (int num: nums) {
            vector<int> copy(2 * sum + 1);
            for (int i = -sum; i <= sum; i++) {
                if (0 <= i - num + sum && 2 * sum >= i - num + sum) {
                    copy[i + sum] += dp[i - num + sum];
                }
                if (0 <= i + num + sum && 2 * sum >= i + num + sum) {
                    copy[i + sum] += dp[i + num + sum];
                }
            }
            dp = copy;
        }

        return dp[target + sum];
    }
};
