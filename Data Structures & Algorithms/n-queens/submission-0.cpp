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

        for (int m: unused) {
            if (!is_valid(permutation, m)) continue;

            unordered_set<int> copy = unused;
            copy.erase(m);
            permutation.push_back(m);

            backtrack(res, n, permutation, copy);

            permutation.pop_back();
        }
    }

    bool is_valid(vector<int> partial_board, int queen) {
        for (int i = 0; i < partial_board.size(); i++) {
            if (abs(partial_board[i] - queen) == partial_board.size() - i) {
                return false;
            }
        }
        return true;
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
