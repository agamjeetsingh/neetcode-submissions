class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;

        int i = 0;
        while (i < nums.size() - 1) {
            cout << i << endl;
            res++;
            int m = 0;
            int max_j = i + 1;
            if (i + nums[i] >= nums.size() - 1) break;
            for (int j = i + 1; j <= i + nums[i]; j++) {
                m = max(m, nums[j]);
                if (m == nums[j]) max_j = j;
            }
            i = max_j;
        }

        return res;
    }
};
