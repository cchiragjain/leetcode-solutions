class Solution {
    private:
        void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& visited){
            int m = grid.size();
            int n = grid[0].size();
            
            queue<pair<int, int>> q;
            visited[row][col] = true;
            
            q.push({row, col});
            vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
            
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
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    visited[i][j] = true;
                    bfs(i, j, grid, visited);
                    count++;
                }
            }
        }

        return count;
    }
};