class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](const vector<int>& p1, const vector<int>& p2) {
            return p1[0]^2 + p1[1]^2 < p2[0]^2 + p2[1]^2;
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);

        for (auto& point: points) {
            pq.push(point);
            if (pq.size() > k) pq.pop();
        }

        vector<vector<int>> res;
        while (!pq.empty()) {
            res.push_back(pq.top()); pq.pop();
        }

        return res;
    }
};
