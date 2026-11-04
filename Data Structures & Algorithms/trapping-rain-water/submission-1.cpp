class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> max_left(height.size());
        vector<int> max_right(height.size());

        // max_left[i] is the maximum height on the left of height[i]

        int res = 0;

        int current_max = INT_MIN;

        for (int i = 0; i < height.size(); i++) {
            current_max = max(current_max, height[i]);
            if (i == 0) {
                max_left[i] = 0; continue;
            }
            max_left[i] = current_max;
        }

        current_max = INT_MIN;

        for (int i = height.size() - 1; i >= 0; i--) {
            current_max = max(current_max, height[i]);
            if (i == height.size() - 1) {
                max_right[i] = 0; continue;
            }
            max_right[i] = current_max;
        }

        for (int i = 0; i < height.size(); i++) {
            res += max(0, min(max_left[i], max_right[i]) - height[i]);
        }

        return res;
    }
};
