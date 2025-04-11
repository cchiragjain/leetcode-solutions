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
        vector<vector<int>> memo(n, vector<int>(n, -1));

        return minPathSum(0, 0, triangle, memo);
    }
};