/*
    * The minimum way a graph/ can be fully connected is through a spanning tree ( n nodes h aur n - 1 edges )
    * Matlab n computers ko atleast n - 1 wires chaiye ( if this is not the case then -1 not possible )
    * 
*/
class DisjointSet{
public:
    vector<int> parent;
    vector<unsigned long long> size;
    vector<int> rank;

    DisjointSet(int n){
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        // size.resize(n + 1, 1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    int findUltimateParent(int node){
        if(parent[node] == node) return node;
        parent[node] = findUltimateParent(parent[node]);
        return parent[node];
    }

    void unionByRank(int u, int v){
        int upu = findUltimateParent(u);
        int upv = findUltimateParent(v);

        // always connect smaller rank to bigger one
        if(rank[upu] < rank[upv]){
            parent[upu] = upv;
        } else if(rank[upv] < rank[upu]){
            parent[upv] = upu;
        } else{
            parent[upu] = upv;
            rank[upv]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int wires = connections.size();
        if(wires < n - 1) return -1; // if we dont have atleast n - 1 wires then not possible

        // using disjoint set to find number of componets
        // according to spanning tree we need atleast n - 1 edges to make n nodes completely connected

        DisjointSet ds(n);
        int numberOfComponents = 0;

        for(auto connection: connections){
            int u = connection[0];
            int v = connection[1];
            ds.unionByRank(u, v);
        }

        for(int i = 0; i < n; i++) {
            // if any node is there own parent then they form a component
            if(ds.parent[i] == i) numberOfComponents++;
        }

        return numberOfComponents - 1;
    }
};