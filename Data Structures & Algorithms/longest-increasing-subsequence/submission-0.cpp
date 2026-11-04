class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i] = length of LIS starting at index i
        vector<int> dp(nums.size());

        for (int i = nums.size() - 1; i >= 0; i--) {
            dp[i] = 1;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] < nums[j]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
