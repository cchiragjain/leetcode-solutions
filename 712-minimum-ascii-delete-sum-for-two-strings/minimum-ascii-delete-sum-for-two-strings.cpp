class Solution {
private:
    int solve(int i, int j, int m, int n, string& s1, string& s2, vector<vector<int>>& memo){
        if(i >= m && j >= n) return 0;

        // these cases will only be covered once even in we somehow memoize them
        if(i >= m){
            // ex. "" vs "abc" then 3 delete operations will be required
            return s2[j] + solve(i, j + 1, m, n, s1, s2, memo);
        }
        if(j >= n){
            return s1[i] + solve(i + 1, j, m, n, s1, s2, memo);
        }

        if(memo[i][j] != -1) return memo[i][j];

        if(s1[i] == s2[j]) return memo[i][j] = solve(i + 1, j + 1, m, n, s1, s2, memo); // no delete operation is required

        int deleteIFromS1 = s1[i] + solve(i + 1, j, m, n, s1, s2, memo);
        int deleteJFromS2 = s2[j] + solve(i, j + 1, m, n, s1, s2, memo);

        return memo[i][j] = min(deleteIFromS1, deleteJFromS2);
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        // memoisation went from O(2^ (m + n)) to O(m * n)
        // vector<vector<int>> memo(m, vector<int>(n, -1));

        // return solve(0, 0, m, n, s1, s2, memo);

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        // dp[i][j] stores the min delete sum for s1 length i vs s2 length j
        // ex. dp[2][3] will be se vs eat which will have s + a + t as answer
        dp[0][0] = 0;
        for(int i = 1; i <= m; i++){
            dp[i][0] = s1[i - 1] + dp[i - 1][0]; // dp[2][0] will be e + s
        }
        for(int j = 1; j <= n; j++){
            dp[0][j] = s2[j - 1] + dp[0][j - 1]; // dp[2][0] will be e + s
        }

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s1[i - 1] == s2[j - 1]){
                    // no delete operation is required
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(
                        s1[i - 1] + dp[i - 1][j],
                        s2[j - 1] + dp[i][j - 1]
                    );
                }
            }
        }

        return dp[m][n];
    }
};