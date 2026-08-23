class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;

        int l = 0;
        int r = heights.size() - 1;

        while (l < r) {
            // cout << heights[l] << " " << heights[r] << endl;
            // cout << "area: " << (r - l) * min(heights[l], heights[r]) << endl;
            res = max(res, (r - l) * min(heights[l], heights[r]));

            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }

        return res;
    }
};
