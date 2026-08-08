class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> q;
        vector<bool> visited(m * n);

        auto index = [&](int r, int c) { return r * n + c; };
        
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == 'X') continue;
                for (auto& dir: directions) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];

                    if (nr < 0 || nc < 0 || nr >= m || nc >= n) {
                        q.push({r, c});
                        visited[index(r, c)] = true;
                        break;
                    }
                }
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();

            for (auto& dir: directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;

                if (board[nr][nc] == 'O' && !visited[index(nr, nc)]) {
                    q.push({nr, nc});
                    visited[index(nr, nc)] = false;
                }
            }
        }

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == 'O' && !visited[index(r, c)]) {
                    board[r][c] = 'X';
                }
            }
        }

        return;
    }
    
};
