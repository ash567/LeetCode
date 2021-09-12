class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int ownShareProfit = -prices[0]-fee, notOwnShareProfit = 0, N = prices.size();
        for(int i = 1; i < N; i++) {
            notOwnShareProfit = max(notOwnShareProfit, ownShareProfit + prices[i]);
            ownShareProfit = max(ownShareProfit, notOwnShareProfit - prices[i] - fee);
        }
        return notOwnShareProfit;
    }
};
