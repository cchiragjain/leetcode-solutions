/*
    Can use normal queue in this since the weights are unit 
*/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] != 0) return -1; // if initial is not 0 then cant reach end

        int n = grid.size();

        queue<pair<int, pair<int, int>>> q; // stores distance taken till this vs (row, col)

        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        
        q.push({1, {0, 0}}); // distance to reach {0,0} is 1
        distance[0][0] = 1;

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}}; // can go in eight directions

        while(!q.empty()){
            auto config = q.front();
            q.pop();

            int distanceTillHere = config.first;
            int row = config.second.first;
            int col = config.second.second;

            if(row == n - 1 && col == n - 1){
                return distanceTillHere;
            }

            for(auto& [dy, dx]: directions){
                int newRow = row + dy;
                int newCol = col + dx;

                // agar valid config h and this is a shorter path
                if(newRow < n && newRow >= 0 && newCol < n && newCol >= 0 && grid[newRow][newCol] == 0 && distanceTillHere + 1 < distance[newRow][newCol]){
                    distance[newRow][newCol] = distanceTillHere + 1;
                    q.push({distanceTillHere + 1, {newRow, newCol}});
                }
            }  
        }

        return -1;
    }
};