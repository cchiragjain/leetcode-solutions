// think of n as index can go from n -> 0

class Solution {
private:
    int climbStairs(int n, vector<int>& dp){
        if(n == 0 || n == 1) return 1;

        if(dp[n] != -1) return dp[n];

        dp[n] = climbStairs(n - 1, dp) + climbStairs(n - 2, dp);
        return dp[n];
    }
    
public:
    // similar to fibonacci sequence
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);

        return climbStairs(n, dp);
    }

    /* recursive
    // this function returns number of ways it takes to reach from n to 0
    int climbStairs(int n) {
        if(n == 0 || n == 1) return 1; // if we at 0 then only 1 way exists to reach 0 ( do nothing )
        // if we at 1 then can take 1 step
        
        // if climbStairs(n) return number of ways from n -> 0
        // then climbStairs(n - 1) will return number of ways from n - 1 -> 0
        int numberOfWaysIfWeTakeOneStep = climbStairs(n - 1);
        int numberOfWaysIfWeTakeTwoSteps = climbStairs(n - 2);

        // problem asks for count of all ways return sum
        return numberOfWaysIfWeTakeOneStep + numberOfWaysIfWeTakeTwoSteps;
    }
    */
};