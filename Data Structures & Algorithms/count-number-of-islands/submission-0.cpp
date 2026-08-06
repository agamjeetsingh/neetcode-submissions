class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        stack<int> st;
        vector<bool> visited(m * n);
        int res = 0;
        
        for (int i = 0; i < m * n; i++) {
            if (visited[i] || get(grid, i) == '0') continue;
            res++;
            st.push(i);

            while (!st.empty()) {
                int top = st.top(); st.pop();
                if (visited[top]) continue;
                visited[top] = true;

                if (top % n != 0 && get(grid, top - 1) == '1') st.push(top - 1);
                if ((top + 1) % n != 0 && get(grid, top + 1) == '1') st.push(top + 1);
                if (top >= n && get(grid, top - n) == '1') st.push(top - n);

                if (top + n < m * n && get(grid, top + n) == '1') st.push(top + n);
            }
        }

        return res;
    }

    char get(vector<vector<char>>& grid, int index) {
        return grid[index / grid[0].size()][index % grid[0].size()];
    }
};
