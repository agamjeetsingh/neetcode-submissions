class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l = 0;
        int r = n - 1;

        while (l < r) {
            int guess = numbers[l] + numbers[r];
            if (guess == target) return {l + 1, r + 1};
            if (guess < target) {
                l++;
            } else {
                r--;
            }
        }
    }
};
