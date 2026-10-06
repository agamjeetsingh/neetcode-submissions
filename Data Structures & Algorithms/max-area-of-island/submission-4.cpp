class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        stack<pair<int, int>> st;
        
        int res = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) continue;
                grid[r][c] = 0;

                int size = 0;

                st.push({r, c});

                while (!st.empty()) {
                    auto [r, c] = st.top(); st.pop();
                    size++;

                    for (auto& dir: directions) {
                        int i = dir[0]; int j = dir[1];
                        int nr = r + i;
                        int nc = c + j;
                        if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                            grid[nr][nc] = 0;
                            st.push({nr, nc});
                        }
                    }
                }

                res = max(res, size);
            }
        }
        
        return res;
    }
};
