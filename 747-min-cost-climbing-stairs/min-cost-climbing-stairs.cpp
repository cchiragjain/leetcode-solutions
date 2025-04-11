class Solution {
private:
    int minCost(vector<int>& cost, int i, vector<int>& memo){
        if(i == 0 || i == 1) return cost[i]; // can start from here so they both will have there min cost
        if(memo[i] != -1) return memo[i];

        int costOne = minCost(cost, i - 1, memo);
        int costTwo = minCost(cost, i - 2, memo);
        
        memo[i - 1] = costOne;
        memo[i - 2] = costTwo;

        return cost[i] + min(costOne, costTwo);
    }
    
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n, -1); // stores step vs min Cost calculated
        // the calls will be since using the same memo
        return min(minCost(cost, n - 1, memo), minCost(cost, n - 2, memo));
    }
};