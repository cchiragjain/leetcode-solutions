/*
    * Uses tarjans alogrithm
    * Basically for each node we find the lowest time/ node from which we can reach this node except from the parent
    * if the lowest time for any adjacent node is greater than that of the current node we can break this connection/ this is a bridge
    * but if the low time is less or equal then that means there exists some other node through which we can reach this node so no point in breaking this edge 
*/
class Solution {
private:
    void dfs(int src, int parent, int time, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& tin, vector<int>& low, vector<vector<int>>& result){
        visited[src] = true;
        tin[src] = time;
        low[src] = time;
        time++;

        for(int neighbour: adj[src]){
            if(neighbour == parent) continue;

            if(!visited[neighbour]){
                // apna dfs karke la
                dfs(neighbour, src, time, adj, visited, tin, low, result);
                // update the low time it may update on dfs call of neighbour
                low[src] = min(low[src], low[neighbour]);

                // if at any time neighbours low is higher than time for insertion of our src node then that means that there exists no other path through which this node can be visited so we can break this edge
                if(low[neighbour] > tin[src]){
                    result.push_back({src, neighbour});
                }
            } else {
                // if already visited then no way this edge can be broken
                // just update with low time if foudn
                low[src] = min(low[src], low[neighbour]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vector<vector<int>> result;

        vector<bool> visited(n, false);

        vector<int> tin(n, -1); // stores time to reach this node/ time of insertion
        vector<int> low(n, -1); // stores the lowest time to reach this node from all adjacent nodes

        for(auto edge: connections){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, -1, 0, adj, visited, tin, low, result);

        return result;
    }
};