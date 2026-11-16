class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ordering;

        vector<int> inDegrees(numCourses);
        vector<vector<int>> adjList(numCourses);
        vector<bool> visited(numCourses);

        for (auto& edge: prerequisites) {
            inDegrees[edge[0]]++;
            adjList[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegrees[i] == 0) {
                q.push(i);
                visited[i] = true;
            }
        }

        while (!q.empty()) {
            int front = q.front(); q.pop();

            ordering.push_back(front);

            for (int neighbour: adjList[front]) {
                if (visited[neighbour]) continue;

                if (--inDegrees[neighbour] == 0); {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }

        return ordering.size() == numCourses;
    }
};
