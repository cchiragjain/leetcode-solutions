class Solution {
private:
    int solve(int idx, int amount, vector<int>& coins, vector<vector<int>>& memo){
        if(amount == 0) return 1; // there exists a way in which we can reach end
        if(idx >= coins.size()) return 0;

        if(memo[idx][amount] != -1) return memo[idx][amount];

        if(amount < coins[idx]){
            // the coin size at this idx is more than the amount we need can take this coin 
            return solve(idx + 1, amount, coins, memo);
        }

        // if we take this coin again can take this (infinite supply exists)
        int take = solve(idx, amount - coins[idx], coins, memo);
        int notTake = solve(idx + 1, amount, coins, memo);

        return memo[idx][amount] = take + notTake;
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        // recursion is ( 2 ^ n + amount)
        // memoisation is N * amount
        // vector<vector<int>> memo(n, vector<int>(amount + 1, -1));

        // return solve(0, amount, coins, memo);
        // dp[i][j] will give for i - 1 th index array number of ways to get j amount

        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(amount + 1, 0));
        
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
             // there is one way to use n coins for 0 amount
             // do nothing
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= amount; j++){
                unsigned long long take = 0;

                if(coins[i - 1] <= j){
                    // take what ever ways we can do for
                    // this many coins and less amount
                    // can use same coin mulitple times
                    take = dp[i][j - coins[i - 1]];
                }

                // dont use this coin and check how many ways for before coins with the same amount
                unsigned long long notTake = dp[i - 1][j];

                dp[i][j] = take + notTake;
            }
        }

        return dp[n][amount];
    }
};