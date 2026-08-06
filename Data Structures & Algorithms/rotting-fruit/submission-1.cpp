class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();

        queue<pair<int, int>> q;
        int res = 0;

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                    grid[r][c] = 0;
                }
            }
        }

        if (q.empty()) return 0;

        while (!q.empty()) {
            int size = q.size();
            res++;
            
            for (int i = size; i > 0; i--) {
                auto [row, col] = q.front(); q.pop();
                cout << row << ", " << col << endl;
                
                for (auto& dir: directions) {
                    int nr = row + dir.first;
                    int nc = col + dir.second;
                    
                    if (nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == 1) {
                        grid[nr][nc] = 0;
                        q.push({nr, nc});
                    }
                }
            }
            cout << "\n----" << endl;
        }

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) return -1;
            }
        }

        return res - 1;
    }
};
