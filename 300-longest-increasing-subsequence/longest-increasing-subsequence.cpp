class Solution {
private:
    int solve(int i, int prev, int n, vector<int>& nums, vector<vector<int>>& memo){
        if(i >= n) return 0;
        
        if(prev != -1 && memo[i][prev] != -1) return memo[i][prev];

        int take = INT_MIN;

        if(prev == -1 || nums[prev] < nums[i]){
            // take
            take = 1 + solve(i + 1, i, n, nums, memo);
        }

        int notTake = solve(i + 1, prev, n, nums, memo);
        if(prev != -1) memo[i][prev] = max(take, notTake);

        // take and not take
        return max(
            take, notTake
        );
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // memoisation T.C => O(2^n) to O(n^2)
        // vector<vector<int>> memo(n, vector<int>(n, -1));

        // return solve(0, -1, n, nums, memo);

        vector<int> dp(n, 1); // dp[i] defines length of increasing subsequence ending at index i. by default each is a subsequence of its own so all have 1 length
        int maxLength = 1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                // if can be part of subsequence then check whether if including i in the subsequence of j increases our length or not
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1); // if we include i in the subsequence of j or keep it as it is
                    maxLength = max(dp[i], maxLength);
                }
            }
        }

        return maxLength;
    }
};