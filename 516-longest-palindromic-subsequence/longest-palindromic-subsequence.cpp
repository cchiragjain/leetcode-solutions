class Solution {
private:
// refer lcs for explanation
    int lcs(string& s1, string& s2){
        int m = s1.length();
        int n = s2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
public:
    int longestPalindromeSubseq(string s) {
        string s_rev = s;
        reverse(s_rev.begin(), s_rev.end());

        return lcs(s, s_rev);
    }
};