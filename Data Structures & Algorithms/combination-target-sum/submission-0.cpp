class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
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
            combination.push_back(nums[i]);
            backtrack(nums, target, res, combination, i, sum + nums[i]);
            combination.pop_back();
        }
    }
};
