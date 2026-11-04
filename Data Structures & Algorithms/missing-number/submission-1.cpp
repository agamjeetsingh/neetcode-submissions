class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i <= nums.size(); i++) {
            res = res ^ i;
        }
        for (int num: nums) {
            res = res ^ num;
        }

        return res;
    }
};
