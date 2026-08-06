class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int area = 0;
        stack<pair<int, int>> st;

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 0) continue;
                st.push({r, c});
                grid[r][c] = 0;

                while (!st.empty()) {
                    area++;
                    auto [row, col] = st.top(); st.pop();

                    for (auto& dir: directions) {
                        int nr = row + dir.first;
                        int nc = col + dir.second;
                        
                        if (nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == 1) {
                            grid[nr][nc] = 0;
                            st.push({nr, nc});
                        }
                    }
                }
                res = max(res, area);
                area = 0;
            }
        }

        return res;
    }
};
