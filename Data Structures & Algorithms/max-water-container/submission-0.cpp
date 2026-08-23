class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;

        int l = 0;
        int r = heights.size() - 1;

        while (l < r) {
            res = max(res, (r - l) * min(heights[l], heights[r]));

            if (min(heights[l], heights[r - 1]) > min(heights[l + 1], heights[r])) {
                r--;
            } else {
                l++;
            }
        }

        return res;
    }
};
