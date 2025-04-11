class Solution {
private:
    int uniquePaths(int m, int n, vector<vector<int>>& memo){
        if(m == 1 && n == 1) return 1;
        if(m == 0 || n == 0) return 0;

        if(memo[m][n] != -1) return memo[m][n];
        // if we are at m,n then calculate all paths in which we came from the top and the ones in which we came from the left
        memo[m][n] = uniquePaths(m - 1, n, memo) + uniquePaths(m, n - 1, memo);
        return memo[m][n];
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));

        return uniquePaths(m, n, memo);
    }
};