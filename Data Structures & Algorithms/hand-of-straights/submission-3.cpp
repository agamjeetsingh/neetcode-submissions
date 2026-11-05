class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        multiset<int> ms(hand.begin(), hand.end());
        if (hand.size() % groupSize != 0) return false;

        for (int i = 0; i < hand.size() / groupSize; i++) {
            int min = *ms.begin();
            for (int j = 0; j < groupSize; j++) {
                auto it = ms.find(min + j);
                if (it != ms.end()) {
                    ms.erase(it);
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};
