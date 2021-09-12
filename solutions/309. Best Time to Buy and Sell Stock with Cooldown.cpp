// Note: if you look initialization condition, cash = 0 holds true for i = 1... So when you are caculating these values in loop, you calculate them (cash, hold, cashWithLock) for the next iteration.
    
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cash = 0, hold = -prices[0], cashWithLock = 0, localHold;
        for(int i = 1; i < prices.size(); i++) {
            localHold = hold;
            hold = max(hold, cash - prices[i]);
            cash = max(cash, cashWithLock);
            cashWithLock = localHold + prices[i];
        }
        return max(cash, cashWithLock);
    }
};
