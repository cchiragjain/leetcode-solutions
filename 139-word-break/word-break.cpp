class Solution {
private:
    unordered_set<string> st;

    bool solve(int idx, int n, string& s, vector<int>& memo){
        if(idx >= n) {
            return true; // if say searching leet then code only way for idx to reach here is if the entire stirng was able to break
        }

        if(st.find(s) != st.end()){
            return true; // this word already present
        }

        if(memo[idx] != -1) return memo[idx];

        for(int l = 1; l <= n; l++){
            string temp = s.substr(idx, l); // keep on creating new substrings starting from this idx
            // ex. leetcode
            // check if l exists and then make call to break eetcode
            if(st.find(temp) != st.end() && solve(idx + l, n, s, memo)) return memo[idx] = true;
        }

        return memo[idx] = false; // if not able to break
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();

        vector<int> memo(n, -1);

        for(string& word: wordDict){
            st.insert(word);
        }

        return solve(0, n, s, memo);
    }
};