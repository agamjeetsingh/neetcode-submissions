class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int res = INT_MIN;
        for (int num: nums) {
            sum += num;
            res = max(res, sum);
            if (sum < 0) sum = 0;
        }

        return res;
    }
};
