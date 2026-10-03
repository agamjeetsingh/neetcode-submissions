class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<unordered_set<int>> freq(nums.size() + 1);
        unordered_map<int, int> mp;

        for (int num: nums) {
            freq[0].insert(num);
            mp[num] = 0;
        }

        for (int num: nums) {
            int f = mp[num];
            freq[f].erase(num);
            freq[f + 1].insert(num);
            mp[num] = f + 1;
        }

        vector<int> res;
        for (int i = nums.size(); i >= 0; i--) {
            for (int n: freq[i]) {
                res.push_back(n);
                if (res.size() == k) break;
            }
            if (res.size() == k) break;
        }

        return res;
    }
};
