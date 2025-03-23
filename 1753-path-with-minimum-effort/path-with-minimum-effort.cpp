#define P pair<int, pair<int, int>>

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        int result = 0;

        priority_queue<P, vector<P>, greater<P>> pq; // min heap stores distance vs {row, col}

        vector<vector<int>> distance(rows, vector<int>(cols, INT_MAX));
        distance[0][0] = 0;
        pq.push({0, {0, 0}});

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while(!pq.empty()){
            auto config = pq.top();
            pq.pop();

            int minEffortTillHere = config.first;
            int row = config.second.first;
            int col = config.second.second;

            if(row == rows - 1 && col == cols - 1){
                return minEffortTillHere;
            }

            for(auto& [dy, dx]: directions){
                int newRow = row + dy;
                int newCol = col + dx;

                if(newRow < rows && newRow >= 0 && newCol < cols && newCol >= 0 && max(abs(heights[row][col] - heights[newRow][newCol]), minEffortTillHere) < distance[newRow][newCol]){
                    distance[newRow][newCol] = max(abs(heights[row][col] - heights[newRow][newCol]), minEffortTillHere);
                    pq.push({distance[newRow][newCol], {newRow, newCol}});
                }
            }
        }

        return result;
    }
};