class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num: nums) sum += num;
        int target = sum / 2;
        if (sum % 2 == 1) return false;
        vector<bool> dp(target + 1);
        dp[0] = true;



        for (int num: nums) {
            vector<bool> copy = dp;
            for (int i = num; i <= target; i++) {
                if (copy[i - num]) {
                    dp[i] = true;
                }
            }
        }

        return dp.back();
    }
};
