class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        auto comp = [](pair<int, int> p1, pair<int, int> p2) {
            return p1.first < p2.first;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);


        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0]; int y = points[i][1];
            pq.push({x*x + y*y, i});
            if (pq.size() > k) {
                // cout << "popping: {" << points[pq.top().second][0] << ", " << points[pq.top().second][1] << "}" << endl;
                pq.pop();
            }
        }

        vector<vector<int>> res;

        while (!pq.empty()) {
            res.push_back(points[pq.top().second]);
            pq.pop();
        }

        return res;
    }
};
