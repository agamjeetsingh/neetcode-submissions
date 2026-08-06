class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int area = 0;

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 0) continue;
                dfs(grid, r, c);
                res = max(res, area);
                area = 0;
            }
        }

        return res;
    }

    void dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || (grid[r][c] == 0)) {
            return;
        }
        area++;
        grid[r][c] = 0;
        
        for (auto& dir: directions) {
            int nr = r + dir.first;
            int nc = c + dir.second;

            dfs(grid, nr, nc);
        }
    }
};
