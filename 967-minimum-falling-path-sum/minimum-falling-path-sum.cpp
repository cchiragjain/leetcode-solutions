class Solution {
private:
    int minFallingPathSum(int i, int j, int n, vector<vector<int>>& matrix, vector<vector<int>>& memo){
        if(i < 0 || j < 0) return INT_MAX;
        if(i >= n || j >= n) return INT_MAX;
        // if at the last row
        if(i == n - 1 && j < n) return matrix[i][j]; 
        
        if(memo[i][j] != -1) return memo[i][j];
        
        memo[i][j] = matrix[i][j] + min(
            minFallingPathSum(i + 1, j - 1,n, matrix, memo),
            min(
                minFallingPathSum(i + 1, j,n, matrix, memo),
                minFallingPathSum(i + 1, j + 1,n, matrix, memo)
            )
        );

        return memo[i][j];
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        int minSum = INT_MAX;

        // memoisation giving tle
        // vector<vector<int>> memo(n, vector<int>(n, -1));

        // for(int i = 0; i < n; i++){
        //     // get the minimum sum from the first row
        //     minSum = min(minFallingPathSum(0, i, n, matrix, memo), minSum);
        // }

        // tabulation
        // vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        // for(int i = 0; i < n; i++){
        //     dp[0][i] = matrix[0][i];
        // }

        // for(int i = 1; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         int topLeftValue = j > 0 ? dp[i - 1][j - 1] : INT_MAX;
        //         int topValue = dp[i - 1][j];
        //         int topRightValue = j + 1 != n ? dp[i - 1][j + 1] : INT_MAX;

        //         dp[i][j] = matrix[i][j] + min(topLeftValue, min(topValue, topRightValue));
        //     }
        // }

        // for(int j = 0; j < n; j++){
        //     minSum = min(minSum, dp[n - 1][j]);
        // }

        vector<int> prev(matrix[0]);
        for(int i = 1; i < n; i++){
            vector<int> curr(n, INT_MAX);
            for(int j = 0; j < n; j++){
                int topLeftValue = j > 0 ? prev[j - 1] : INT_MAX;
                int topValue = prev[j];
                int topRightValue = j + 1 != n ? prev[j + 1] : INT_MAX;        
                curr[j] = matrix[i][j] + min(topLeftValue, min(topValue, topRightValue));

            }
            prev = curr;
        }
        for(int j = 0; j < n; j++){
            minSum = min(minSum, prev[j]);
        }
        return minSum;
    }
};