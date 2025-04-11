class Solution {
private:
    // function that returns all unique paths count from 0, 0 to i, j
    int uniquePaths(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& memo){
        if(i == 0 && j == 0 && grid[i][j] != 1) return 1;
        if(i < 0 || j < 0) return 0;
        if(grid[i][j] == 1) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        
        int pathsFromTop = uniquePaths(i - 1, j, grid, memo);
        int pathsFromLeft = uniquePaths(i, j - 1, grid, memo);

        memo[i][j] = pathsFromTop + pathsFromLeft;
        return memo[i][j];
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return 0;
        
        int m = grid.size();
        int n = grid[0].size();

        // memoisation
        // vector<vector<int>> memo(m, vector<int>(n, -1));
        // return uniquePaths(m - 1, n - 1, grid, memo);

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) continue;

                if(grid[i][j] != 1){
                    int topValue = i > 0 ? dp[i - 1][j] : 0;
                    int leftValue = j > 0 ? dp[i][j - 1] : 0;

                    dp[i][j] = topValue + leftValue;
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};