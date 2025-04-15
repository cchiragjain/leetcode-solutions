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
        // recursion is ( 2 ^ n + amount)
        int n = coins.size();

        vector<vector<int>> memo(n, vector<int>(amount + 1, -1));

        return solve(0, amount, coins, memo);
    }
};