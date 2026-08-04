class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<unordered_set<int>> freqs(n + 1);
        unordered_map<int, int> mp; // mp[num] = frequency
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (!mp.contains(num)) continue;
            mp.insert({num, 0});
            freqs[0].insert(num);
        }

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int freq = mp[num]++;
            freqs[freq].erase(num);
            freqs[freq + 1].insert(num);
        }

        int counter = 0;
        vector<int> res;

        for (auto it = freqs.rbegin(); it != freqs.rend(); it++) {
            for (int num : *it) {
                res.push_back(num);
                if (++counter == k) {
                    return res;
                }
            }
        }
    }
};
