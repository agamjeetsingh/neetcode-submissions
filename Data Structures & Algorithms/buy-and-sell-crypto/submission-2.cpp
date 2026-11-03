class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int least_price = prices[0];

        for (int price: prices) {
            max_profit = max(max_profit, price - least_price);
            least_price = min(least_price, price);
        }

        return max_profit;
    }
};
