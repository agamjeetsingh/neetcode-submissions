class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int lo = 0;
        int hi = matrix.size() * n - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            int guess = matrix[mid / n][mid % n];

            if (guess == target) {
                return true;
            } else if (guess > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return false;
    }
};
