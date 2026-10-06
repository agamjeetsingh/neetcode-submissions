class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int res = 0;

        queue<int> q;
        vector<bool> visited(n);

        vector<vector<int>> adjList(n);

        for (auto& edge: edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            visited[i] = true;
            q.push(i);
            res++;

            while (!q.empty()) {
                int front = q.front(); q.pop();

                for (int neighbour: adjList[front]) {
                    if (visited[neighbour]) continue;
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        return res;
    }
};
