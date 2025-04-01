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
    
public:
    int fib(int n) {
        vector<int> dp(n + 1, -1); // need to return the nth fib number
        
        int result = solveUsingMem(n, dp);
        return result;    
    }
};