class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int leastPrice = INT_MAX;
        int res = 0;

        for (int price: prices) {
            res = max(res, price - leastPrice);
            leastPrice = min(leastPrice, price);
        }
        return res;
    }
};
