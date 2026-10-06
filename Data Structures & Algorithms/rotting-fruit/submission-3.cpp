class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        queue<pair<int, int>> q;

        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int total = 0;
        
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 2) {
                    total++;
                    q.push({r, c});

                }
            }
        }

        int res = -1;

        while (!q.empty()) {
            int size = q.size();
            cout << size << endl;
            res++;

            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front(); q.pop();

                for (auto& dir: dirs) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                        if (grid[nr][nc] != 2) total++;
                        if (grid[nr][nc] == 1) q.push({nr, nc});
                        grid[nr][nc] = 2;
                    }
                }
            }
        }

        return total == m * n ? (res == -1 ? 0 : res) : -1;
    }
};
