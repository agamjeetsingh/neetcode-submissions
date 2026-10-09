class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int sum = 0;
        
        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];
            res = max(res, sum);

            if (sum < 0) sum = 0;
        }

        return res;
    }
};
