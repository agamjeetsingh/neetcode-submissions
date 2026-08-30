class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        if (sum % 2 == 1) return false;

        int target = sum / 2;

        vector<bool> dp(target + 1);
        dp[0] = true;

        for (int i = 1; i <= target; i++) {
            for (int num: nums) {
                dp[i] = dp[i] || (i >= num && dp[i - num]);
            }
        }
        return dp.back();
    }
};
