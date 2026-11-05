class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;

        vector<int> newInterval = intervals[0];
        
        for (const vector<int>& interval: intervals) {
            if (newInterval[1] < interval[0]) {
                res.push_back(newInterval);
                newInterval = interval;
            } else if (newInterval[0] > interval[1]) {
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
