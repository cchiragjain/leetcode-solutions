// if we just work on the basis of cost then there can be paths such that which may be cheaper in cost but the total steps may be larger to reach there
#define pii pair<int, pair<int, int>>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adjList(n);
        for(auto& edge: flights){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adjList[u].push_back({v, wt});
        }

        vector<int> minCost(n, INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii>> pq; // stops vs (node, cost)

        minCost[src] = 0;
        pq.push({0, {src, 0}});

        while(!pq.empty()){
            auto config = pq.top();
            pq.pop();

            int stops = config.first;
            int node = config.second.first;
            int cost = config.second.second;

            if(stops > k) continue; // skip this path

            for(auto it: adjList[node]){
                int adjacentNode = it.first;
                int edgeWeight = it.second;

                if(cost + edgeWeight < minCost[adjacentNode] && stops <= k){
                    minCost[adjacentNode] = cost + edgeWeight;
                    pq.push({stops + 1, {adjacentNode, minCost[adjacentNode]}});
                }
            }
        }

        return minCost[dst] != INT_MAX ? minCost[dst] : -1;
    }
};