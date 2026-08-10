class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());

        int res = INT_MAX;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (works(piles, h, mid)) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }

    bool works(vector<int>& piles, int h, int k) {
        int cost = 0;
        for (int pile : piles) {
            cost += (pile + k - 1) / k;
        }
        return cost <= h;
    }
};
