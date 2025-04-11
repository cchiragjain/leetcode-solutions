class Solution {
    // returns the min path sum for row to the bottom of triangle considering both i and i + 1 indexes
private:
    int minPathSum(int row, int i, vector<vector<int>>& triangle, vector<vector<int>>& memo){
        if(row >= triangle.size()) return 0;
        
        if(memo[row][i] != -1) return memo[row][i];

        int leftPathSum = minPathSum(row + 1, i, triangle, memo);
        int rightPathSum = minPathSum(row + 1, i + 1, triangle, memo);

        memo[row][i] = triangle[row][i] + min(leftPathSum, rightPathSum);

        return memo[row][i];
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // vector<vector<int>> memo(n, vector<int>(n, -1));

        // return minPathSum(0, 0, triangle, memo);

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        
        dp[0][0] = triangle[0][0];

        for(int i = 1; i < n; i++){
            for(int j = 0; j < triangle[i].size(); j++){
                int topValue = dp[i - 1][j];
                int topLeftValue = j > 0 ? dp[i - 1][j - 1] : INT_MAX;

                dp[i][j] = triangle[i][j] + min(topValue, topLeftValue);
            }
        }

        int minValue = INT_MAX;
        for(int i = 0; i < n; i++){
            minValue = min(minValue, dp[n - 1][i]);
        }
        return minValue;
    }
};