class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> mp;

        for (int num: hand) mp[num]++;

        if (hand.size() % groupSize != 0) return false;

        for (int i = 0; i < hand.size() / groupSize; i++) {
            auto [min, _] = *mp.begin();
            for (int j = 0; j < groupSize; j++) {
                if (!mp.contains(min + j)) {
                    return false;
                } else {
                    if (--mp[min + j] == 0) {
                        mp.erase(min + j);
                    }
                }
            }
        }

        return true;
    }
};
