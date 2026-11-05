class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int res = 0;

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        stack<pair<int, int>> st;
        vector<bool> visited(m * n);

        for (int i = 0; i < m * n; i++) {
            if (grid[i / n][i % n] == '0' || visited[i]) continue;
            visited[i] = true;
            st.push({i / n, i % n});

            while (!st.empty()) {
                auto [r, c] = st.top(); st.pop();

                for (auto [i, j]: dirs) {
                    int nr = r + i;
                    int nc = c + j;

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr * n + nc] && grid[nr][nc] == '1') {
                        visited[nr * n + nc] = true;
                        st.push({nr, nc});
                    }
                }
            }

            res++;
        }

        return res;
    }
};
