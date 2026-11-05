class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> combination;

        backtrack(nums, 0, res, combination);

        return res;
    }

    void backtrack(vector<int>& nums, int start, vector<vector<int>>& res, vector<int>& combination) {
        res.push_back(combination);
        if (start >= nums.size()) return;
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            combination.push_back(nums[i]);
            backtrack(nums, i + 1, res, combination);
            combination.pop_back();
        }
    }
};
