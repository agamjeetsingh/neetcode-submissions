class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        for (int i = 0; i < nums.size() && nums[i] <= 0; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r) {
                if (nums[l] + nums[r] + nums[i] == 0) {
                    res.push_back({{nums[i], nums[l], nums[r]}});
                    do { l++; } while (l < r && nums[l] == nums[l - 1]);
                } else if (nums[l] + nums[r] + nums[i] < 0) {
                    do { l++; } while (l < r && nums[l] == nums[l - 1]);
                } else {
                    do { r--; } while (l < r && nums[r] == nums[r + 1]);
                }
            }
        }

        return res;
    }
};
