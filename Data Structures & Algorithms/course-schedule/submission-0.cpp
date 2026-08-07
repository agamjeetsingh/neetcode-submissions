class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegrees(numCourses);

        vector<vector<int>> adjMap(numCourses);

        vector<int> topOrder;

        for (auto& edge: prerequisites) {
            adjMap[edge[1]].push_back(edge[0]);

            inDegrees[edge[0]]++;
        }

        stack<int> st;

        for (int i = 0; i < numCourses; i++) {
            if (inDegrees[i] == 0) {
                st.push(i);
            }
        }

        while (!st.empty()) {
            int top = st.top(); st.pop();

            topOrder.push_back(top);

            for (int neighbour: adjMap[top]) {
                if (--inDegrees[neighbour] == 0) {
                    st.push(neighbour);
                }
            }
        }

        return topOrder.size() == numCourses;
    }
};
