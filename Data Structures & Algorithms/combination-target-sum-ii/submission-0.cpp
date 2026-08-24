class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> combination;

        sort(nums.begin(), nums.end());

        backtrack(nums, target, res, combination, 0, 0);

        return res;
    }

    void backtrack(vector<int>& nums, int target, vector<vector<int>>& res, vector<int>& combination, int start, int sum) {
        if (target == sum) {
            res.push_back(combination);
        } else if (target < sum) {
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            // [1, 2, 2, 4, 5, 6, 9]
            if (i > start && nums[i] == nums[i - 1]) continue;
            combination.push_back(nums[i]);
            backtrack(nums, target, res, combination, i + 1, sum + nums[i]);
            combination.pop_back();
        }
    }
};
