class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> combination;
        sort(nums.begin(), nums.end());
        backtrack(nums, target, 0, 0, res, combination);

        return res;
    }

    void backtrack(vector<int>& nums, int target, int sum, int start, vector<vector<int>>& res, vector<int>& combination) {
        if (target < sum) return;
        if (target == sum) {
            res.push_back(combination);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            combination.push_back(nums[i]);
            backtrack(nums, target, sum + nums[i], i + 1, res, combination);
            combination.pop_back();
        }
    }
};
