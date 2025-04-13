class Solution {
private:
    // function which given i, j position returns its maximum Side length possible
    int maximumSideLength(int i, int j, int m, int n, vector<vector<char>>& matrix, vector<vector<int>>& memo){
        if(i >= m || j >= n) return 0;
        if(matrix[i][j] == '0') return 0;
        
        if(memo[i][j] != -1) return memo[i][j];

        int right = maximumSideLength(i, j + 1, m, n, matrix, memo);
        int down = maximumSideLength(i + 1, j, m, n, matrix, memo);
        int diagonal = maximumSideLength(i + 1, j + 1, m, n, matrix, memo);

        // if we are at a 1 then one length side is there
        // min [2,3,4] say then we can form 2 area rectangel using all three sides
        memo[i][j] = 1 + min(right, min(down, diagonal));
        return memo[i][j];
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // vector<vector<int>> memo(m, vector<int>(n, -1));

        // int maxSides = 0;

        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < n; j++){
        //         if(matrix[i][j] == '1'){
        //             maxSides = max(maximumSideLength(i, j, m,n, matrix, memo), maxSides);
        //         }
        //     }
        // }

        // return maxSides * maxSides;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxSides = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1') dp[i][j] = 1;
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(dp[i][j] == 1){
                    int left = j > 0 ? dp[i][j - 1] : 0;
                    int diagonal = i > 0 && j > 0 ? dp[i - 1][j - 1] : 0;
                    int top = i > 0 ? dp[i - 1][j] : 0;
                    dp[i][j] = 1 + min(left, min(diagonal, top));
                    maxSides = max(maxSides, dp[i][j]);
                }
            }
        }

        return maxSides * maxSides;
    }
};