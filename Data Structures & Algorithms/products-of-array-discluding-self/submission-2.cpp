class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size());
        vector<int> right(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                left[i] = 1;
            } else {
                left[i] = left[i - 1] * nums[i - 1];
            }
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i == nums.size() - 1) {
                right[i] = 1;
            } else {
                right[i] = right[i + 1] * nums[i + 1];
            }
        }

        vector<int> res(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            res[i] = left[i] * right[i];
        }

        return res;
    }
};
