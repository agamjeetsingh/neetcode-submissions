class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        queue<pair<int, int>> q; // num, index

        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            while (!q.empty() && q.front().first < nums[i]) {
                q.pop();
            }
            if (q.size() == k) {
                q.pop();
            }
            q.push({nums[i], i});
            
            if (i >= k - 1) res.push_back(q.front().first);
        }

        return res;
    }
};
