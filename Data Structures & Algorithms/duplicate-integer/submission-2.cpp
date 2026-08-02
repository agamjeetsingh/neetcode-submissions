class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> s;

        for (int i = 0; i < nums.size(); i++) {
            if (s.contains(i)) {
                return true;
            }
            s.add(nums[i]);
        }
        return false;
    }
};