class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});
        vector<int> combination;
        backtrack(res, nums, combination, 0);

        return res;
    }

    void backtrack(vector<vector<int>>& res, vector<int>& nums, vector<int>& combination, int start) {
        for (int i = start; i < nums.size(); i++) {
            combination.push_back(nums[i]);
            res.push_back(combination);
            backtrack(res, nums, combination, i + 1);
            combination.pop_back();
        }
    }
};
