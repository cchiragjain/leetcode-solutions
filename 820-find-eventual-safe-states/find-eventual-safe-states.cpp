class Solution {
    private:
        bool dfs(int src, vector<bool>& visited, vector<bool>& visitedInPath, vector<bool>& safe, vector<vector<int>>& adj){
            visited[src] = true;
            visitedInPath[src] = true;

            // traverse adjancent nodes
            for(int neighbour: adj[src]){
                if(!visited[neighbour]){
                    // a cycle was found
                    if(dfs(neighbour, visited, visitedInPath, safe, adj)) return true;
                } 
                // if visited already and part of path then cycle exists
                else if(visitedInPath[neighbour]) return true;
            }

            // no cycle was found can mark this node as safe and remove it from the path
            safe[src] = true;
            visitedInPath[src] = false;
            return false;
        }
public:
    /*
        * Approach
        * For dfs based approach if any node is part of a cycle or there is any path in it that leads to a cycle then any such node cannot have a path that leads to a terminal node
        * the path will get stuck in the cycle only
        * we basically call dfs for each node and if there is a cycle then that nodes does not get unmarked from not safe
        * also any node that leads to a node that is part of a cycle gets tracked by the fact that if a cycle is found we dont remove them from the path visited 
    */
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false);
        vector<bool> visitedInPath(n, false);
        vector<bool> safe(n, false); // no node is safe initially
        
        vector<int> result;

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                // cout << i << " ";
                dfs(i, visited, visitedInPath, safe, graph);
            }
        }

        for(int i = 0; i < n; i++){
            cout << safe[i] << " " << i << " " << endl;
            if(safe[i]) result.push_back(i);
        }

        return result;
    }
};