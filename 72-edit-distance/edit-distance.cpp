class Solution {
private:
    int solve(int i, int j, int m, int n, string& s1, string& s2, vector<vector<int>>& memo){
        // if i becomes out of bounds
        // for ex. ab and abc then we need to insert 1 more character 3 - 2 ( n - j )
        if(i >= m) return n - j;
        if(j >= n) return m - i;

        if(memo[i][j] != -1) return memo[i][j];

        if(s1[i] == s2[j]){
            // characters are same no need to do anything solve for next
            return memo[i][j] = solve(i + 1, j + 1, m, n, s1, s2, memo);
        }

        int insert = 1 + solve(i, j + 1, m, n, s1, s2, memo);
        int deleteRes = 1 + solve(i + 1, j, m, n, s1, s2, memo);
        int replace = 1 + solve(i + 1, j + 1, m, n, s1, s2, memo);

        return memo[i][j] = min(insert, min(deleteRes, replace));
    }

public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        // memoisation       
        // vector<vector<int>> memo(m, vector<int>(n, -1));

        // return solve(0, 0, m, n, word1, word2, memo);
    
        // dp[i][j] represents for string1 length i and string2 length j min operations required to convert string1 to string2
        // ex. dp[0][2] will be 2 ex. "" and "ab" need 2 operations to convert "" to ab

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 0; i <= m; i++){
            dp[i][0] = i; // to convert 2 to 0 will require 2 delete operations
        }
        for(int j = 0; j <= n; j++){
            dp[0][j] = j;
        }

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(word1[i - 1] == word2[j - 1]){
                    dp[i][j] = dp[i - 1][j -1]; // same letter no operation is required
                } else {
                    int insertCost = 1 + dp[i][j - 1];
                    int deleteCost = 1 + dp[i - 1][j];
                    int replaceCost = 1 + dp[i - 1][j - 1];

                    dp[i][j] = min(insertCost, min(
                        deleteCost,
                        replaceCost
                    ));
                }
            }
        }

        return dp[m][n];
    }
};