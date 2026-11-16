class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ordering;

        // 2 -> 1 <-> 0

        vector<int> inDegrees(numCourses);
        vector<vector<int>> adjList(numCourses);

        for (auto& edge: prerequisites) {
            inDegrees[edge[0]]++;
            adjList[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegrees[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int front = q.front(); q.pop();

            ordering.push_back(front);

            for (int neighbour: adjList[front]) {

                if (--inDegrees[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        return ordering.size() == numCourses;
    }
};
