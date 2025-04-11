class Solution {
private:
    int minCost(vector<int>& cost, int i, vector<int>& memo){
        if(i == 0 || i == 1) return cost[i]; // can start from here so they both will have there min cost
        if(memo[i] != -1) return memo[i];

        int costOne = minCost(cost, i - 1, memo);
        int costTwo = minCost(cost, i - 2, memo);
        
        memo[i] = cost[i] + min(costOne, costTwo);
        return memo[i];
    }

    int minCost(vector<int>& cost){
        int n = cost.size();

        if(n == 1) return cost[0];

        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i < n; i++){
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        return min(dp[n - 1], dp[n -2]);
    }
    
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n, -1); // stores step vs min Cost calculated
        // the calls will be since using the same memo
        // return min(minCost(cost, n - 1, memo), minCost(cost, n - 2, memo));
        return minCost(cost);
    }
};