class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int x = max(0, nums[0]);
        int res = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int temp = x;
            x = max(0, temp + nums[i]);
            res = max(res, temp + nums[i]);
        }

        return res;
    }
};
