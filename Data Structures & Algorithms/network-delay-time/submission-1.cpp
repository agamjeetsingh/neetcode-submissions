using pii = pair<int, int>;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // {weight, node}
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dist(n + 1, INT_MAX);
        dist[0] = 0; dist[k] = 0; pq.push({0, k});

        vector<vector<pii>> adjList(n + 1);

        for (vector<int>& edge: times) {
            adjList[edge[0]].push_back({edge[1], edge[2]});
        }

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();

            if (d > dist[u]) continue;

            for (auto [v, w]: adjList[u]) {
                if (dist[v] > w + dist[u]) {
                    dist[v] = w + dist[u];
                    pq.push({dist[v], v});
                }
            }
        }

        int max_dist = *max_element(dist.begin(), dist.end());

        return max_dist == INT_MAX ? -1 : max_dist;
    }
};
