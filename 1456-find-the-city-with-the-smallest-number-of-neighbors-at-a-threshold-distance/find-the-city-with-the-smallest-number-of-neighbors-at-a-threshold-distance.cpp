class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        int maxCityCount = n;
        int cityNumber = -1;

        for(auto& edge: edges){
            distance[edge[0]][edge[1]] = edge[2];
            distance[edge[1]][edge[0]] = edge[2]; // undirected graph
        }

        for(int i = 0; i < n; i++) distance[i][i] = 0; // distance from i -> i
        // floyd warshall
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(distance[i][k] == INT_MAX || distance[k][j] == INT_MAX) continue;
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }

        // har city ke adjacent cities ka count if they are less then distance threshold
        // also need to return the larger city number so will check till last
        for(int city = 0; city < n; city++){
            int cityCount = 0;
            for(int adjCity = 0; adjCity < n; adjCity++){
                if(distance[city][adjCity] <= distanceThreshold) cityCount++;
            }
            if(cityCount <= maxCityCount){
                maxCityCount = cityCount;
                cityNumber = city; // this is the city with the 
            }
        }

        return cityNumber;
    }
};