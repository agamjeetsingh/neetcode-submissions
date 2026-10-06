class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int m = board.size(); int n = board[0].size();

        stack<pair<int, int>> st;
        vector<vector<bool>> visited(m, vector<bool>(n));

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == 'X') visited[r][c] = true;
                if (visited[r][c]) continue;

                vector<pair<int, int>> toConvert;
                bool convert = true;

                st.push({r, c});
                toConvert.push_back({r, c});
                visited[r][c] = true;

                if (onEdge(m, n, r, c)) convert = false;

                while (!st.empty()) {
                    auto [r, c] = st.top(); st.pop();

                    for (auto& dir: dirs) {
                        int nr = r + dir[0];
                        int nc = c + dir[1];

                        if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] && board[nr][nc] == 'O') {
                            st.push({nr, nc});
                            visited[nr][nc] = true;
                            toConvert.push_back({nr, nc});
                            if (onEdge(m, n, nr, nc)) convert = false;
                        }
                    }
                }

                if (convert) {
                    for (auto [r, c]: toConvert) {
                        board[r][c] = 'X';
                    }
                }
            }
        }
    }

    static bool onEdge(int m, int n, int r, int c) {
        return r == 0 || c == 0 || r == m - 1 || c == n - 1;
    }
};
