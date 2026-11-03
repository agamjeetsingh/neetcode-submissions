class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<unordered_set<int>> freq(nums.size() + 1);
        unordered_map<int, int> mp(nums.size());

        for (int num: nums) freq[0].insert(num);

        for (int num: nums) {
            freq[mp[num]++].erase(num);
            freq[mp[num]].insert(num);
        }

        vector<int> res;
        
        for (int i = freq.size() - 1; i >= 0; i--) {
            for (int num: freq[i]) {
                if (res.size() == k) return res;
                res.push_back(num);
            }
        }
        
        return res;
    }
};
