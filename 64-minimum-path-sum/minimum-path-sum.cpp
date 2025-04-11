class Solution {
private:
    // returns the min path sum for i, j position in grid
    int minPathSum(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& memo){
        if(i == 0 && j == 0) return grid[0][0];
        if(i < 0 || j < 0) return INT_MAX;
        
        if(memo[i][j] != -1) return memo[i][j];
        
        memo[i][j] = grid[i][j] + min(minPathSum(i - 1, j, grid, memo), minPathSum(i, j - 1, grid, memo));
        return memo[i][j];
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        /* memoisation
        vector<vector<int>> memo(m, vector<int>(n, -1));

        return minPathSum(m - 1, n - 1, grid, memo);
        */

        // tabulation
        
        /*
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = grid[0][0];

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) continue;

                int topValue = i > 0 ? dp[i - 1][j] : INT_MAX;
                int leftValue = j > 0 ? dp[i][j - 1] : INT_MAX;

                dp[i][j] = grid[i][j] + min(topValue, leftValue);
            }
        }
        return dp[m - 1][n - 1];
        */

        // can be further optimised if we see that only needs to store a cells top and left value but each cell top value will be from previous row
        // do dry run 
        vector<int> dp(n, -1);
        dp[0] = grid[0][0];

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n;j++){
                if(i == 0 && j == 0) continue;

                int topValue = i > 0 ? dp[j] : INT_MAX;
                int leftValue = j > 0 ? dp[j - 1] : INT_MAX;

                dp[j] = grid[i][j] + min(topValue, leftValue);
            }
        }

        return dp[n - 1];
    }
};