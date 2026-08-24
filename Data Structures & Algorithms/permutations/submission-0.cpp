class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> permutation;

        backtrack(s, res, permutation);

        return res;
    }

    void backtrack(unordered_set<int>& s, vector<vector<int>>& res, vector<int>& permutation) {
        if (s.empty()) res.push_back(permutation);

        for (int num : s) {
            permutation.push_back(num);
            auto copy = s;
            copy.erase(num);
            backtrack(copy, res, permutation);
            permutation.pop_back();
        }
    }
};
