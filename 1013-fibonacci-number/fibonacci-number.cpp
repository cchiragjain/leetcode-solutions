/*
    * Steps to solve dp problem with top down approach ( recursion + memorisation )
    * Create dp array ( can be 1d, 2d or 3d dimensions depend on number of changing parameter )
    * pass this to recursion function and store answer whenever it gets computed
    * on each call check if answer was already computed or not and return that
*/
class Solution {
private:
    int solveUsingMem(int n, vector<int>& dp){
        if(n <= 1) return n;

        if(dp[n] != -1) return dp[n]; // if already pre computed return that only

        dp[n] = solveUsingMem(n - 1, dp) + solveUsingMem(n - 2, dp);
        return dp[n];
    }

    int solveUsingTabulation(int n){
        if(n <= 1) return n; // base cases can causes issues if say n was 0 then dp will be of size 1 but we will accessing dp[1] etc.

        vector<int> dp(n + 1, -1);

        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2]; // building solutions using previous
        }

        return dp[n];
    }
    
public:
    int fib(int n) {
        // vector<int> dp(n + 1, -1); // need to return the nth fib number
        
        // int result = solveUsingMem(n, dp);
        return solveUsingTabulation(n);    
    }
};