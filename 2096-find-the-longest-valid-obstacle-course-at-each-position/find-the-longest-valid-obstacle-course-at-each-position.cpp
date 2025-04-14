class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        
        // // this is giving tle O(n ^ 2)
        // vector<int> dp(n, 1);

        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < i; j++){
        //         if(obstacles[j] <= obstacles[i]){
        //             dp[i] = max(dp[i], 1 + dp[j]);
        //         }
        //     }
        // }

        // return dp; 

        vector<int> result; // stores final lis
        vector<int> lis; // stores the end elements of the lis

        for (int i = 0; i < n; ++i) {
            int height = obstacles[i];

            // find first element > current
            auto it = upper_bound(lis.begin(), lis.end(), height);

            int len = it - lis.begin(); // length of longest ending here

            if (it == lis.end()) {
                // no subsequence already exists in which we can be a part of create a new
                lis.push_back(height);
            } else {
                // replace with the smaller one to increase further chances
                // ex. update
                *it = height;
            }
            
            result.push_back(len + 1); // +1 since lengths are 1-based
        }

        return result;
    }
};