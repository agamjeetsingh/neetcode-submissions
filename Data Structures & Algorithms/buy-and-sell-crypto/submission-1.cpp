class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int res = 0;
        for (int price: prices) {
            res = max(res, max(0, price - minPrice));
            minPrice = min(minPrice, price);
        }

        return res;
    }
};
