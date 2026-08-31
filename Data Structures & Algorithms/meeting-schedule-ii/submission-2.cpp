/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& i1, const Interval& i2) {
            if (i1.start == i2.start) return i2.end > i1.end;
            return i1.start < i2.start;
        });

        multiset<int> endTimes;

        for (auto& interval: intervals) {
            cout << interval.start << " " << interval.end << endl;
            if (endTimes.empty()) {
                endTimes.insert(interval.end);
            } else {
                int earliestEndTime = *endTimes.begin();
                if (earliestEndTime > interval.start) {
                    endTimes.insert(interval.end);
                } else {
                    endTimes.erase(endTimes.begin());
                    endTimes.insert(interval.end);
                }
            }
        }

        return endTimes.size();
    }
};
