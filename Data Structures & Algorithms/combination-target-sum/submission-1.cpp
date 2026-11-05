class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> combination;

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
            combination.push_back(nums[i]);
            backtrack(nums, target, sum + nums[i], i, res, combination);
            combination.pop_back();
        }
    }
};
