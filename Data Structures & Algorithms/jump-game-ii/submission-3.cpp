class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;
        int i = 0;

        while (i < nums.size() - 1) {
            cout << i << endl;
            res++;

            int m = 0;
            int max_j = i;

            if (i + nums[i] >= nums.size() - 1) break;

            for (int j = i + 1; j < nums.size() && j <= i + nums[i]; j++) {
                if (j + nums[j] > m) {
                    m = j + nums[j];
                    max_j = j;
                }
            }

            i = max_j;
        }

        return res;
    }
};
