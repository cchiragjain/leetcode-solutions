/*
    basic meaning of bipartite graph
    if we can color the graph in 2 colors such that no 2 adjacent node have the same color
    then that graph is bipartite
    - any linear graph will always be this
    - any graph with odd lenght cycle can never be bipartite
    - any graph with even length cycle will be bipartite
*/

class Solution {
    private:
        // normal graph bfs
        bool check(int src, int color, vector<vector<int>>& graph, vector<int>& colors){
            queue<int> q;
            q.push(src);
            colors[src] = color;

            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(int neighbour: graph[node]){
                    if(colors[neighbour] == -1){ // not visited basically
                        colors[neighbour] = !colors[node]; // mark the neighbour color with opposite color since using 0 and 1 as color indicators
                        q.push(neighbour);

                    } 
                    // else if the neighbour color which is adjacent is same as that of
                    // current node then cannot be bipartite
                    else if(colors[neighbour] == colors[node]){
                        return false;
                    }
                }
            }

            return true;
        }

        void printVector(vector<int>& vec){
            for(int a: vec) cout << a << " ";
        }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int m = graph.size();

        vector<int> colors(m, -1); // by default not colored 

        for(int i = 0; i < m; i++){
            if(colors[i] == -1){
                if(check(i, 0, graph, colors) == false) return false; // if any component not bipartite
            }
        }

        printVector(colors);

        return true;        
    }
};