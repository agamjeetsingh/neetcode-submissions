class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;

        queue<int> q;

        vector<vector<int>> adjList(n);
        vector<bool> visited(n);

        for (auto& edge: edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        int found = 1;

        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int front = q.front(); q.pop();

            for (int neighbour: adjList[front]) {
                if (visited[neighbour]) continue;
                visited[neighbour] = true;
                q.push(neighbour);
                found++;
            }
        }

        return found == n;
    }
};
