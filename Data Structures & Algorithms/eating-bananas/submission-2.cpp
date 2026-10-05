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

    bool isValid(vector<int>& piles, int h, int k) {
        int total = 0;
        for (int pile: piles) {
            total += (pile + k - 1) / k;
        }
        return total <= h;
    }
};
