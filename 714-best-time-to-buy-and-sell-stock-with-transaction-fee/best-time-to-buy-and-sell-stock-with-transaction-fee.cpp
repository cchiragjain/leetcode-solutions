class Solution {
// same as buy and sell with cooldown but only while selling we need to subtract fee
// and no cooldown is required
private:
    int solve(int day, int n, vector<int>& prices, bool buyToday, int fee, vector<vector<int>>& memo){
        if(day >= n) return 0;

        if(memo[day][buyToday] != -1) return memo[day][buyToday];

        int profit = 0;
        if(buyToday){
            // two options can or can not buy
            // if buy today need to sell next time
            // cant do multiple transactions
            int buy = solve(day + 1, n, prices, false, fee, memo) - prices[day];
            int notBuy = solve(day + 1, n, prices, true, fee, memo);
            profit = max(profit, max(buy, notBuy));
        } else {
            // no cooldown required also need to give fee
            int sell = solve(day + 1, n, prices, true, fee, memo) + prices[day] - fee;
            int notSell = solve(day + 1, n, prices, false, fee, memo);

            profit = max(profit, max(sell, notSell));
        }

        return memo[day][buyToday] = profit;
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> memo(n, vector<int>(2, -1));

        return solve(0, n, prices, true, fee, memo);
    }
};