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
        vector<vector<int>> memo(m, vector<int>(n, -1));

        return solve(0, 0, m, n, word1, word2, memo);
    }
};