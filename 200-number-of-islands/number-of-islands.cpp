class Solution {
private:
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col, int m, int n){
        queue<pair<int, int>> q;
        visited[row][col] = true;

        q.push({row, col});

        vector<pair<int, int>> directions = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };

        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();

            for(auto& [dy, dx]: directions){
                int newRow = row + dy;
                int newCol = col + dx;

                if(newRow < m && newRow >= 0 && newCol < n && newCol >= 0 && grid[newRow][newCol] == '1' && !visited[newRow][newCol]){
                    visited[newRow][newCol] = true;
                    q.push({newRow, newCol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    count++;
                    bfs(grid, visited, i, j, m, n);
                }
            }
        }

        return count;
    }
};