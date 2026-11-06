class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num: nums) sum += num;
        if (target > sum || target < -sum) return 0;

        // dp[i] = number of ways to get sum (i - sum) with first ? nums
        vector<int> dp(2 * sum + 1);
        dp[sum] = 1;

        for (int num: nums) {
            vector<int> copy = dp;
            
            for (int i = -sum; i <= sum; i++) {
                dp[i + sum] = 0;
                if (0 <= i + sum - num && i + sum - num <= 2 * sum) dp[i + sum] += copy[i + sum - num];
                if (0 <= i + sum + num && i + sum + num <= 2 * sum) dp[i + sum] += copy[i + sum + num];
            }
        }

        return dp[target + sum];
    }
};
