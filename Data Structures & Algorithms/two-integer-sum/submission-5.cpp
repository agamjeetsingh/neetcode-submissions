class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // num -> index

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (mp.contains(target - num)) {
                return {mp[target - num], i};
            }
            mp[num] = i;
        }
    }
};
