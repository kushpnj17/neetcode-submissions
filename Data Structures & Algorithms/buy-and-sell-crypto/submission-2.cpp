class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_price = INT_MAX;
        int l = 0;
        int r = 0;
        while (r < prices.size()){
            int profit = prices[r] - prices[l];
            max_profit = max(max_profit, profit);

            if(prices[r] < min_price){
                l = r;
                min_price = prices[l];
            }
            r++;
        }

        return max_profit;
    }
};
