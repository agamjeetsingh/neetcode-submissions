class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;

        vector<int> permutation;
        unordered_set<int> unused;
        for (int i = 0; i < n; i++) unused.insert(i);

        backtrack(res, n, permutation, unused);

        return res;
    }

    void backtrack(vector<vector<string>>& res, int n, vector<int>& permutation, unordered_set<int>& unused) {
        if (unused.empty()) {
            res.push_back(to_string(permutation));
            return;
        }

        unordered_set<int> forbidden;
        for (int i = 0; i < permutation.size(); i++) {
            int cand1 = permutation[i] - permutation.size() + i;
            int cand2 = permutation[i] + permutation.size() - i;
            if (cand1 >= 0 && cand1 < n) forbidden.insert(cand1);
            if (cand2 >= 0 && cand2 < n) forbidden.insert(cand2);
            // if (abs(permutation[i] - queen) == permutation.size() - i) {
            //     return false;
            // }
        }

        for (int m: unused) {
            if (forbidden.contains(m)) continue;

            unordered_set<int> copy = unused;
            copy.erase(m);
            permutation.push_back(m);

            backtrack(res, n, permutation, copy);

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
