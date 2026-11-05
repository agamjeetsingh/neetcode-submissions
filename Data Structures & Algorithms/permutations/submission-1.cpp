class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_set<int> unused{nums.begin(), nums.end()};
        vector<int> permutation;

        backtrack(unused, res, permutation);

        return res;
    }

    void backtrack(unordered_set<int>& unused, vector<vector<int>>& res, vector<int>& permutation) {
        if (unused.empty()) {
            res.push_back(permutation);
        }

        for (int num: unused) {
            auto copy = unused;
            copy.erase(num);
            permutation.push_back(num);
            backtrack(copy, res, permutation);
            permutation.pop_back();
        }
    }
};
