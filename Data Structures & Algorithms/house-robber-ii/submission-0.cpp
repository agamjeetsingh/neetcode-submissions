class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int n = nums.size();
        vector<int> dp1(n);
        vector<int> dp2(n);

        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        dp2[1] = nums[1];

        for (int i = 2; i < n; i++) {
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);
        }

        for (int i = 2; i < n; i++) {
            if (i == n - 1) {
                dp1[i] = dp1[i - 1];
            } else {
                dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
            }
        }

        return max(dp1.back(), dp2.back());
    }
};
