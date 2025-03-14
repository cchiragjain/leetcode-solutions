class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> distance(m, vector<int>(n, 0));
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        queue<pair<pair<int, int>, int>>
            q; // stores {row, col} vs steps it took to reach there
        vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({{i, j}, 0}); // initial config for queue
                    // if any data is 1 then it is at 0 distance from the
                    // nearest 1
                    visited[i][j] = true;
                }
            }
        }

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int stepsTillHere = q.front().second;

            q.pop();
            // update in result matrix
            distance[row][col] = stepsTillHere;

            for (pair<int, int> p : directions) {
                int dy = p.first;
                int dx = p.second;

                int newRow = row + dy;
                int newCol = col + dx;

                if (newRow < m && newRow >= 0 && newCol < n && newCol >= 0 &&
                    !visited[newRow][newCol]) {
                    // visit this node
                    // it will take 1 more step from current
                    visited[newRow][newCol] = true;
                    q.push({{newRow, newCol}, stepsTillHere + 1});
                }
            }
        }

        return distance;
    }
};