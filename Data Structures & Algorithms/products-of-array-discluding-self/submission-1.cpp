class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pred(nums.size()); // pred[i] is product of everything left of i^th index
        vector<int> succ(nums.size()); // succ[i] is product of everything right of i^th index

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                pred[i] = 1;
            } else {
                pred[i] = nums[i - 1] * pred[i - 1];
            }
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i == nums.size() - 1) {
                succ[i] = 1;
            } else {
                succ[i] = nums[i + 1] * succ[i + 1];
            }
        }
        
        vector<int> res(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            res[i] = pred[i] * succ[i];
        }
        return res;
    }
};
