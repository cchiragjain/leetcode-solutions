class Solution {
private:
    int solve(int i, int j, int m, int n, string& s1, string& s2, vector<vector<int>>& memo){
        if(j >= n) return 1; // were able to use all of j 
        if(i >= m) return 0; // all of i was used before j could be exhausted

        if(memo[i][j] != -1) return memo[i][j];

        if(s1[i] == s2[j]){
            // there are two cases now we can either say take this as starting point of our subsequence
            // or not take since there may be other such s1[i] as well
            // take + not take
            // in both we are increasing i since need to check for j
            return memo[i][j] = solve(i + 1, j + 1, m, n, s1, s2, memo) + solve(i + 1, j, m, n, s1, s2, memo);
        } else {
            // no other choice but to skip i
            return memo[i][j] = solve(i + 1, j, m, n, s1, s2, memo);
        }
    }

public:
    int numDistinct(string s, string t) {
        // very brute way will be to generate all subsequence of 2 and then (2 ^ m) and then go through all of them and update count if = t.

        int m = s.length();
        int n = t.length();

        vector<vector<int>> memo(m, vector<int>(n, -1));

        return solve(0, 0, m, n, s, t, memo);
    }
};