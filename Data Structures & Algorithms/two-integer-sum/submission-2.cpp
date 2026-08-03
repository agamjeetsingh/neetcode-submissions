class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (mp.contains(target - num)) {
                return {mp[target-num], i};
            }
            mp.insert({num, i});
        }
        return {};
    }
};
