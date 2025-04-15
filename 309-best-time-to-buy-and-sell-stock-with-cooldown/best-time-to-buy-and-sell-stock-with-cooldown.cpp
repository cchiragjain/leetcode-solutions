class Solution {
private:
    int solve(int day, int n, vector<int>& prices, bool needToBuy, vector<vector<int>>& memo){
        if(day >= n) return 0; // can earn 0 profit now
        if(memo[day][needToBuy] != -1) return memo[day][needToBuy];

        int profit = 0;

        if(needToBuy){
            // if need to buy then there are two options either buy it and reduce prices[day] from our profit
            // and then call for selling
            int buy = solve(day + 1, n, prices, false, memo) - prices[day];
            // can also not buy today and check for other days
            int notBuy = solve(day + 1, n, prices, true, memo); // try to buy other day
            profit = max(profit,
                max(
                    notBuy,
                    buy
                )
            );
        } else {
            // need to sell today with a cooldown
            // there are still options can either sell or not sell
            // if selling today then can buy parso also aaj ka paisa profit mein jud jaaega
            int sell = prices[day] + solve(day + 2, n, prices, true, memo);
            int notSell = solve(day + 1, n, prices, false, memo);
            
            profit = max(profit,
                max(
                    notSell,
                    sell
                )
            );
        }

        return memo[day][needToBuy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1) return 0;

        // memoisation O(2 ^ n) -> O(N)
        // vector<vector<int>> memo(n, vector<int>(2, -1));

        // // will always be buying the stock on first day
        // return solve(0, n, prices, true, memo);

        // tabulation method
        vector<int> dp(n, 0); // stores max profit possible for ith day at i - 1 position
        dp[0] = 0; // need to always buy on the first day
        dp[1] = max(prices[1] - prices[0], 0); // can be say [1,2] then can buy for 1 and sell for 2 with max profit of 1 but for say [2,1] then buy on 2(0 profit) and sell on 1(-1 profit) so 0 max profit

        for(int i = 2; i < n; i++){
            // for each day find the best possible price that we should have bought this stock on for and then sell today this will be today profit
            // but also need previous profit
            dp[i] = dp[i - 1]; // max profit till now
            for(int j = 0; j < i; j++){
                int todayProfit = prices[i] - prices[j];
                int previousProfit = j >= 2 ? dp[j - 2] : 0; // now if we are buying on jth day then we could not have bought on j - 1 day also could not have sold on that day as well since need a cooldown 
                dp[i] = max(dp[i], todayProfit + previousProfit);
            }
        }

        for(int num: dp){ 
            cout << num << " ";
        }

        return dp[n - 1];
    }
};