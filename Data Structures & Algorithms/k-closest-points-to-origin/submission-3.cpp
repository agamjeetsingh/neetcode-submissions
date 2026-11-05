class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](const vector<int>& p1, const vector<int>& p2) {
            return p1[0] * p1[0] + p1[1] * p1[1] < p2[0] * p2[0] + p2[1] * p2[1];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);

        for (auto& point: points) {
            pq.push(point);
            if (pq.size() > k) {
                cout << "Popping: x = " << pq.top()[0] << ", y = " << pq.top()[1];
                pq.pop();
            }
        }

        vector<vector<int>> res;
        while (!pq.empty()) {
            res.push_back(pq.top()); pq.pop();
        }

        return res;
    }
};
