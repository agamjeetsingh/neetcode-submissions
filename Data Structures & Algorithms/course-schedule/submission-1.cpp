class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegrees(numCourses);
        int count = 0;

        vector<vector<int>> adjList(numCourses);

        for (const vector<int>& pre: prerequisites) {
            adjList[pre[1]].push_back(pre[0]);
            inDegrees[pre[0]]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (inDegrees[i] == 0) {
                q.push(i);
                count++;
            }
        }

        while (!q.empty()) {
            int front = q.front(); q.pop();

            for (int neighbour: adjList[front]) {
                if (--inDegrees[neighbour] == 0) {
                    q.push(neighbour);
                    count++;
                }
            }
        }

        return count == numCourses;
    }
};
