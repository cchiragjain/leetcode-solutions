class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // brute O(M * N) count all 
        // better will be to for each row find first negative element using binary search
        // all after it will be negative only and increase count
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        int row = 0;
        int col = n - 1;

        while(row < m && col >= 0){
            if(grid[row][col] < 0){
                count += m - row;
                col--;
            } else {
                row++;
            }
        }

        return count;
    }
};