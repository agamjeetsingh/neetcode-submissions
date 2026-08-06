class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();

        queue<pair<int, int>> q;
        int res = 0;

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        auto index = [&](int r, int c) {
            return r * n + c;
        };

        for (int i = 0; i < m * n; i++) {
            if (grid[i / n][i % n] == 2) {
                q.push({i / n, i % n});
            }
        }

        while (!q.empty()) {
            res++;
            int size = q.size();

            for (int i = size; i > 0; i--) {
                auto [r, c] = q.front(); q.pop();

                for (auto& dir: directions) {
                    int nr = r + dir.first;
                    int nc = c + dir.second;

                    if (nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
            }
        }

        for (int i = 0; i < m * n; i++) {
            if (grid[i / n][i % n] == 1) {
                return -1;
            }
        }

        return res - 1;
    }
};
