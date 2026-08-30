class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reachable = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > max_reachable) break;
            max_reachable = max(max_reachable, i + nums[i]);
        }

        return max_reachable >= nums.size() - 1;
    }
};
