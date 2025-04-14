class Solution {
public:
    int t[501][501];
    
    int LCS(string& s1, string& s2, int m, int n) {
        if(m == 0 || n == 0)
            return t[m][n] = 0;
        
        if(t[m][n] != -1)
            return t[m][n];
        
        if(s1[m-1] == s2[n-1])
            return t[m][n] = 1 + LCS(s1, s2, m-1, n-1);
        
        return t[m][n] = max(LCS(s1, s2, m, n-1), LCS(s1, s2, m-1, n));
    }
    
    int minInsertions(string s) {
        int m = s.length();
        
        memset(t, -1, sizeof(t));
        string temp = s;
        reverse(begin(temp), end(temp));
        
        int lcs_length = LCS(s, temp, m, m);
        
        return m - lcs_length;
    }
};