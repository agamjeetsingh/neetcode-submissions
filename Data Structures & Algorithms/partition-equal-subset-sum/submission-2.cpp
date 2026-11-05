class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num: nums) sum += num;
        int target = sum / 2;
        if (sum % 2 == 1) return false;
        vector<bool> dp(target + 1);
        dp[0] = true;

        for (int i = 1; i <= target; i++) {
            for (int num: nums) {
                if (i >= target && dp[i - target]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp.back();
    }
};
