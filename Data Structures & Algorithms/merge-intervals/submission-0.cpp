class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& i1, const vector<int>& i2) {
            if (i1[0] == i2[0]) return i1[1] < i2[1];
            return i1[0] < i2[0];
        });

        vector<vector<int>> res;
        bool first = true;
        vector<int> newInterval;

        for (vector<int>& interval: intervals) {
            if (first) {
                newInterval = interval;
                first = false;
                continue;
            }
            if (newInterval[1] < interval[0]) {
                res.push_back(newInterval);
                newInterval = interval;
            } else if (interval[1] < newInterval[0]) {
                res.push_back(interval);
            } else {
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
            }
        }
        res.push_back(newInterval);
        
        return res;
    }
};
