class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<bool>>& visited, vector<pair<int, int>>& directions){
        int m = board.size();
        int n = board[0].size();

        visited[row][col] = true;

        for(auto& [dy,dx] : directions){
            int newRow = row + dy;
            int newCol = col + dx;

            if(newRow < m && newRow >=0 && newCol < n && newCol >= 0 && !visited[newRow][newCol] && board[newRow][newCol] == 'O'){
                visited[newRow][newCol] = true;
                dfs(newRow, newCol, board, visited, directions);
            }
        }
    }

    void printVector(vector<vector<bool>>& visited){
        for(int i = 0; i < visited.size(); i++){
            for(int j = 0; j < visited[0].size();j++){
                cout << visited[i][j] << " ";
            }
            cout << endl;
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // traverse all boundaries of board and if there is a 0 mark that place as visited
        // if from boundary there is 0 then all 0 that touch this cannot be converted to X

        // top row
        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O' && !visited[0][j]){
                dfs(0, j, board, visited, directions);
            }
        }

        // left col
        for(int j = 0; j < m; j++){
            if(board[j][0] == 'O' && !visited[j][0]){
                dfs(j, 0, board, visited, directions);
            }
        }

        // right col
        for(int j = 0; j < m; j++){
            if(board[j][n - 1] == 'O' && !visited[j][n - 1]){
                dfs(j, n - 1, board, visited, directions);
            }
        }

        // bottom row
        for(int j = 0; j < n; j++){
            if(board[m - 1][j] == 'O' && !visited[m - 1][j]){
                dfs(m - 1, j, board, visited, directions);
            }
        }

        printVector(visited);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n;j++){
                if(visited[i][j] == false) board[i][j] = 'X';
            }
        }
    }
};