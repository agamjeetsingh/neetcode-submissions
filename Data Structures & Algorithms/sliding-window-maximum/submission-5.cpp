class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // decreasing order

        deque<int> dq;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            while (!dq.empty() && dq.back() < nums[i]) dq.pop_back();
            dq.push_back(nums[i]);

            if (i >= k - 1) {
                if (i >= k && dq.front() == nums[i - k]) dq.pop_front();

                res.push_back(dq.front());
            }
        }

        return res;
    }
};
