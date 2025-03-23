#define PII pair<int, int>
#define PLI pair<long long, int>
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<PII>> adjList(n);
        vector<long long> distance(n, LLONG_MAX);
        vector<int> ways(n, 0); // stores number of times we reach this node in
        // case of shortest path passes through this node
        priority_queue<PLI, vector<PLI>, greater<PLI>> pq;
        int mod = 1e9 + 7;

        for(auto& road: roads){
            int u = road[0];
            int v = road[1];
            int wt = road[2];

            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }

        distance[0] = 0;
        ways[0] = 1; // only 1 way possible for source node
        pq.push({0, 0}); // distance vs node

        while(!pq.empty()){
            long long distanceTillHere = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it: adjList[node]){
                int adjNode = it.first;
                int edgeWeight = it.second;

                if(distanceTillHere + edgeWeight < distance[adjNode]){
                    distance[adjNode] = distanceTillHere + edgeWeight;
                    pq.push({distance[adjNode], adjNode});
                    // initially this will be the number of ways or whenever we find the shortest path
                    ways[adjNode] = ways[node];
                } 
                // already discovered shortest distance before just add to existing wasy
                else if(distanceTillHere + edgeWeight == distance[adjNode]){
                    ways[adjNode] = (ways[adjNode] % mod) + (ways[node] % mod);
                }
            }
        }

        return ways[n - 1] % mod;
    }
};