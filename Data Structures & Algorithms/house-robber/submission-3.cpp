class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        int m1 = nums[0];
        int m2 = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            int temp = m2;
            m2 = max(m2, m1 + nums[i]);
            m1 = temp;
        }

        return m2;
    }
};
