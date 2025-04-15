class Solution {
private:
    int solve(vector<int>& squares, int num, vector<int>& memo){
        if(num == 0) return 0;
        if(memo[num] != -1) return memo[num];

        int result = INT_MAX;
        for(int i = 0; i < squares.size(); i++){
            if(squares[i] <= num)
                result = min(result, 1 + solve(squares, num - squares[i], memo));
        }

        return memo[num] = result;
    }
public:
    int numSquares(int n) {
        // vector<int> squares;

        // can do this in the above loop only
        // for(int i = 1; i <= (int)sqrt(n); i++){
        //     squares.push_back(i * i);
        // }

        // memoised O(sqrt n ^ n) => O(n * sqrt n)
        // vector<int> memo(n + 1, -1);

        // return solve(squares, n, memo);

        // T.C => O(n * sqrt n)
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= (int)(sqrt(i)); j++){
                int square = j * j;
                if(i - square >= 0){
                    dp[i] = min(dp[i], 1 + dp[i - square]);
                }
            }
        }

        return dp[n];
    }
};