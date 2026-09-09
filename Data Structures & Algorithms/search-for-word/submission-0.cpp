class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (backtrack(board, word, 0, i, j)) return true;
            }
        }

        return false;
    }

    bool backtrack(vector<vector<char>>& board, string& word, int index, int i, int j) {
        if (index >= word.size()) return true;
        board[i][j] = '#';

        if (i + 1 < board.size() && board[i + 1][j] == word[index]) {
            if (backtrack(board, word, index + 1, i + 1, j)) return true;
            board[i + 1][j] = word[index];
        }

        if (j + 1 < board[0].size() && board[i][j + 1] == word[index]) {
            if (backtrack(board, word, index + 1, i, j + 1)) return true;
            board[i][j + 1] = word[index];
        }

        if (i > 0 && board[i - 1][j] == word[index]) {
            if (backtrack(board, word, index + 1, i - 1, j)) return true;
            board[i - 1][j] = word[index];
        }

        if (j > 0 && board[i][j - 1] == word[index]) {
            if (backtrack(board, word, index + 1, i, j - 1)) return true;
            board[i][j - 1] = word[index];
        }

        return false;
    }
};
