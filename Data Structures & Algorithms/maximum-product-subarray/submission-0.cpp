class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // posDp[i] = most positive until nums[i] including nums[i]
        // negDp[i] = most negative until nums[i] including nums[i]
        vector<int> posDp(nums.size());
        vector<int> negDp(nums.size());

        posDp[0] = nums[0] < 0 ? 0 : nums[0];
        negDp[0] = nums[0] > 0 ? 0 : nums[0];

        int res = posDp[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > 0) {
                posDp[i] = nums[i] * posDp[i - 1];
                negDp[i] = nums[i] * negDp[i - 1];
            }
            if (nums[i] <= 0) {
                posDp[i] = nums[i] * negDp[i - 1];
                negDp[i] = nums[i] * posDp[i - 1];
            }

            res = max(res, posDp[i]);
        }

        return res;
    }
};
