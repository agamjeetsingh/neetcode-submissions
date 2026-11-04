class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (isValid(piles, h, mid)) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    }

    bool isValid(const vector<int>& piles, int h, int rate) {
        int count = 0;

        for (int pile: piles) {
            count += (pile + rate - 1) / rate;
        }

        return count <= h;
    }
};
