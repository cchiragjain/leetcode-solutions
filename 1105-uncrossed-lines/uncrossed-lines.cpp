class Solution {
private:
    int dp[501][501];
    int solve(int i, int j, int m, int n, vector<int>& nums1, vector<int>& nums2){
        if(i >= m || j >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(nums1[i] == nums2[j]) {
            return dp[i][j] = 1 + solve(i + 1, j + 1, m, n, nums1, nums2);
        } else {
            int fix_i = solve(i, j + 1, m, n, nums1, nums2);
            int fix_j = solve(i + 1, j, m, n, nums1,nums2);

            return dp[i][j] = max(fix_i, fix_j);
        }
    }

public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        // recursion + memoisation m * n
        // memset(dp, -1, sizeof(dp));
        // return solve(0, 0, m, n, nums1, nums2);
    
        memset(dp, 0, sizeof(dp));
        // its better to use vector though
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(nums1[i - 1] == nums2[j - 1]){
                    // ex 1 2 vs 3 2
                    // 2 and 2 are equal now check how many possible for 1 and 3
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};