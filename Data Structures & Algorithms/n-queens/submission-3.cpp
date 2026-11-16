class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;

        vector<int> permutation;

        backtrack(res, n, permutation);

        return res;
    }

    void backtrack(vector<vector<string>>& res, int n, vector<int>& permutation) {
        if (permutation.size() == n) {
            res.push_back(to_string(permutation));
            return;
        }

        unordered_set<int> forbidden;
        for (int i = 0; i < permutation.size(); i++) {
            int cand1 = permutation[i] - permutation.size() + i;
            int cand2 = permutation[i] + permutation.size() - i;
            if (cand1 >= 0 && cand1 < n) forbidden.insert(cand1);
            if (cand2 >= 0 && cand2 < n) forbidden.insert(cand2);
            forbidden.insert(permutation[i]);
        }

        for (int i = 0; i < n; i++) {
            if (forbidden.contains(i)) continue;

            permutation.push_back(i);

            backtrack(res, n, permutation);

            permutation.pop_back();
        }
    }

    vector<string> to_string(const vector<int>& board) {
        vector<string> res;

        for (int pos: board) {
            string s;
            s += string(pos, '.');
            s += 'Q';
            s += string(board.size() - 1 - pos, '.');
            res.push_back(s);
        }

        return res;
    }
};
