class DisjointSet{
private:
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int n){
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    int findParent(int node){
        if(parent[node] != node) parent[node] = findParent(parent[node]);
        return parent[node];
    }

    bool isConnected(int u, int v){
        return findParent(u) == findParent(v);
    }

    void unionBySize(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        
        if(pu == pv) return;

        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    int getSize(int node){ 
        return size[node];
    }
};

/*
    Create a disjoint set since it is a graph with dynamic edges
    Now merge all islands together that are 1 so that they are connected if possible in the 4 directions
    Again traverse the grid and for every 0 check adjacent cells if 1 then add there parents size for island size calculation if this parent was not already counted ex. below case 0 the size may get calculated multiple times if we dont consider parent
    1 1 1
    1 0 1
    1 1 1
*/
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        int maxIslandSize = 0;
        
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        // make connected components
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    for(auto& [dy, dx]: directions){
                        int newRow = i + dy;
                        int newCol = j + dx;
                        int originalCellNumberMapping = i * n + j;
                        int adjacentCellNumberMapping = newRow * n + newCol;

                        // if valid config and is a land cell and not already connected then connect
                        if(newRow < n && newRow >= 0 && newCol < n && newCol >= 0 && grid[newRow][newCol] == 1 && !ds.isConnected(originalCellNumberMapping, adjacentCellNumberMapping)){
                            ds.unionBySize(originalCellNumberMapping, adjacentCellNumberMapping);
                        }
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    unordered_set<int> parents;
                    int islandSize = 0;
                    for(auto& [dy, dx]: directions){
                        int newRow = i + dy;
                        int newCol = j + dx;
                        int originalCellNumberMapping = i * n + j;
                        int adjacentCellNumberMapping = newRow * n + newCol;
                        // insert parents of all such 1 adjacent 1's we can find to a set to avoid duplicate parents
                        // we can use this to calculate sizes afterwards
                        if(newRow < n && newRow >= 0 && newCol < n && newCol >= 0 && grid[newRow][newCol] == 1){
                            parents.insert(ds.findParent(adjacentCellNumberMapping));
                        }
                    }

                    for(auto it: parents){
                        islandSize += ds.getSize(it); // add sizes of all others
                    }

                    islandSize++; // will also count self
                    maxIslandSize = max(islandSize, maxIslandSize);
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            maxIslandSize = max(maxIslandSize, ds.getSize(i));
        }

        return maxIslandSize;
    }
};