class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        // sort since we can pick in any order and to form largest such that a,b c,d b < c then best to sort
        sort(pairs.begin(), pairs.end());
    
        vector<int> dp(n, 1);
        int maxVal = 1;
        // variant of lis only

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(pairs[j][1] < pairs[i][0]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                    maxVal = max(dp[i], maxVal);
                }
            }
        }

        return maxVal;
    }
};