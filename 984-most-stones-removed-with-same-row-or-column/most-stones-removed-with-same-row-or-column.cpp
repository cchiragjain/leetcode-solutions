/*
    * If we look closely from a single component we can remove all stones except the last 1.
    * So we can basically derive ans = each component - 1 => all stones - count of components
*/
class DisjointSet{
private:
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int n){
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i <= n;i++){
            parent[i] = i;
        }
    }    

    int findParent(int node){
        if(parent[node] != node) parent[node] = findParent(parent[node]);
        return parent[node];
    }

    void unionBySize(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += pu;
        } else {
            parent[pv] = pu;
            size[pu] += pv;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        // to find count of components we can either use dfs and count no of dfs calls or we can use union find and then find number of unique parents
        int n = stones.size();
        DisjointSet ds(n); // using stones[i] as tracker in this case
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                // if shares same row or same column with any stone coordinate then union stone position
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                ds.unionBySize(i, j);            
                }
            }
        }
        unordered_set<int> seen;

        for(int i = 0; i < n; i++){
            if(seen.find(ds.findParent(i)) == seen.end()){
                seen.insert(ds.findParent(i));
            }
        }

        int numberOfConnectedComponents = seen.size();
        
        return n - numberOfConnectedComponents;
    }
};