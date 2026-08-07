class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n);
        queue<int> q;

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int front = q.front(); q.pop();

            for (int neighbour: adj[front]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        for (int vis: visited) {
            if (!vis) return false;
        }

        return edges.size() == n - 1;
    }
};
