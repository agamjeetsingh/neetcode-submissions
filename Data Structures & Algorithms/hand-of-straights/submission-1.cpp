class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        map<int, int> freqs;
        set<int> s;
        for (int num: hand) {
            freqs[num]++;
            s.insert(num);
        }
        while (!s.empty()) {
            int count = 0;
            int last = *s.begin();
            vector<int> removal;
            for (int num: s) {
                if (++count > groupSize) break;
                if (num != last && num != last + 1) return false;
                last = num;
                if (--freqs[num] == 0) removal.push_back(num);
            }
            for (int num: removal) {
                s.erase(num);
            }
        }

        return true;
    }
};
