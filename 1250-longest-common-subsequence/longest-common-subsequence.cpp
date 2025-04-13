class Solution {
private:
    int solve(string& s1, string& s2, int i, int j, vector<vector<int>>& memo){
        if(i >= s1.length() || j >= s2.length()){
            return 0;
            // if any string becomes "" then 0 length subsequence is there
        }

        if(memo[i][j] != -1) return memo[i][j];

        // exmaple if standing at abcde and ace a are equal then start finding max length of bcde and ce
        if(s1[i] == s2[j]) {
            memo[i][j] = 1 + solve(s1, s2, i + 1, j + 1, memo); 
            return memo[i][j];
        }

        // if thats not the case then check for both cases bcde vs ce and cde vs ace
        return memo[i][j] = max(solve(s1, s2, i + 1, j, memo), solve(s1, s2, i, j + 1, memo));
    }

public:
    int longestCommonSubsequence(string s1, string s2) {
        vector<vector<int>> memo(s1.length(), vector<int>(s2.length(), -1));

        return solve(s1, s2, 0, 0, memo);
    }
};