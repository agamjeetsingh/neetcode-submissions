class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int num = nums[i];
            if (num > 0) break;

            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r) {
                int guess = nums[l] + nums[r];

                if (guess + num > 0) {
                    r--;
                } else if (guess + num < 0) {
                    l++;
                } else {
                    res.push_back({num, nums[l], nums[r]});
                    r--;
                    l++;
                }
            }
        }

        return res;
    }
};
