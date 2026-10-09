class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = max(0, nums[0]);
        int res = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(0, dp[i - 1] + nums[i]);
            res = max(res, dp[i - 1] + nums[i]);
        }

        return res;
    }
};
