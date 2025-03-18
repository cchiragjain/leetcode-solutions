class Solution {
    private:
        vector<int> getTopologicalSort(vector<int>& inDegree, vector<vector<int>>& adjList){
            queue<int> q;
            vector<int> result;

            for(int i = 0; i < inDegree.size(); i++){
                if(inDegree[i] == 0) q.push(i);
            }

            while(!q.empty()){
                int node = q.front();
                q.pop();

                result.push_back(node);

                for(int neighbour: adjList[node]){
                    inDegree[neighbour]--;
                    if(inDegree[neighbour] == 0) q.push(neighbour);
                }
            }
            return result;
        }
        
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses);

        // create adj list
        for(auto& dependenctCourses: prerequisites){
            int course = dependenctCourses[0];
            int prerequisite = dependenctCourses[1];
            adjList[prerequisite].push_back(course);
        }

        // using adjList create indegree array
        for(int i = 0; i < numCourses; i++){
            vector<int> edges = adjList[i];
            for(auto& edge: edges){
                inDegree[edge]++;
            }
        }

        // get topological sorting if its size is equal to numCourses then can exhaust
        // all dependencies or else there exists a cycle
        vector<int> topologicalSorting = getTopologicalSort(inDegree, adjList);
        if(topologicalSorting.size() == numCourses) return true;

        return false;
    }
};