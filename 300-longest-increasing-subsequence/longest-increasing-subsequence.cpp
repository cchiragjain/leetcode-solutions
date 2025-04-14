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
        vector<vector<int>> memo(n, vector<int>(n, -1));

        return solve(0, -1, n, nums, memo);
    }
};