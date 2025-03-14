/*
Any problem that involves a grid with neighbors (up, down, left, right) can often be modeled as an implicit graph:
Each cell is a node.
An edge exists between adjacent (up, down, left, right) cells.
*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>, int>> q; // stores { row, col, time }
        vector<vector<int>> visited(n, vector<int>(m, 0));

        int freshCount = 0; // how many fresh oranges exist before
        // to check if at the end we were able to completely rot all or not
        int maxTime = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    visited[i][j] = 2; // using 2 as visited indicator ( basically this orange has rotted )
                } else if(grid[i][j] == 0) {
                    visited[i][j] = 0;
                } else if(grid[i][j] == 1){
                    freshCount++;
                }
            }
        }

        vector<pair<int, int>> directions = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}}; // standing at [i,j] these all are the directions i can take

        // normal bfs
        while(!q.empty()){
            auto p = q.front();
            q.pop();

            int row = p.first.first;
            int col = p.first.second;
            int time = p.second;

            maxTime = max(time, maxTime);

            for(auto& [dy,dx]: directions){
                int newRow = row + dy;
                int newCol = col + dx;

                // if valid matrix config and not visited and is a rotten orange
                if(newRow < n && newRow >= 0 && newCol < m && newCol >= 0 && visited[newRow][newCol] == 0 && grid[newRow][newCol] == 1){
                    visited[newRow][newCol] = 2;
                    q.push({{newRow, newCol}, time + 1});
                    freshCount--;
                }
            }
        }

        return freshCount == 0 ? maxTime : -1;
    }
};