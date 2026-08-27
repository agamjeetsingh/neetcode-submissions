class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        multiset<int> s(stones.begin(), stones.end());

        while (s.size() > 1) {
            int top1 = *prev(s.end());
            s.erase(prev(s.end()));
            int top2 = *prev(s.end());
            s.erase(prev(s.end()));
            s.insert(abs(top1 - top2));
        }

        return *s.begin();
    }
};
