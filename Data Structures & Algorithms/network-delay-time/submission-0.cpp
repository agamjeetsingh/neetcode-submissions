using pii = pair<int, int>;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pii>> adjList(n + 1); // adjList[u] = {{weight, neighbour}}

        for (auto& edge: times) {
            adjList[edge[0]].emplace_back(edge[2], edge[1]);
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        dist[0] = 0;
        
        // distance, node
        priority_queue<pii, vector<pii>, less<pii>> pq;

        pq.push({0, k});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();

            if (d != dist[u]) continue;

            for (auto [w, v]: adjList[u]) {
                if (w + dist[u] < dist[v]) {
                    dist[v] = w + dist[u];
                    pq.push({dist[v], v});
                }
            }
        }

        int res = *max_element(dist.begin(), dist.end());

        return res == INT_MAX ? -1 : res;
    }
};
