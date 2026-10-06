class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        stack<pair<int, int>> st;
        
        int res = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == '0') continue;
                grid[r][c] = '0';
                res++;

                st.push({r, c});

                while (!st.empty()) {
                    auto [r, c] = st.top(); st.pop();

                    for (auto& dir: directions) {
                        int i = dir[0]; int j = dir[1];
                        int nr = r + i;
                        int nc = c + j;
                        if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == '1') {
                            grid[nr][nc] = '0';
                            st.push({nr, nc});
                        }
                    }
                }
            }
        }
        
        return res;
    }
};
