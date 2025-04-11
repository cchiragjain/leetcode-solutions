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
        vector<vector<int>> memo(m, vector<int>(n, -1));

        return minPathSum(m - 1, n - 1, grid, memo);
    }
};