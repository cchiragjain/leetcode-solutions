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
        memset(dp, -1, sizeof dp);
        return solve(0, 0, m, n, nums1, nums2);
    }
};