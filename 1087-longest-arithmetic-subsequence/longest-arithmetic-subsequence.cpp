class Solution {
private:
    int solve(int idx, int n, vector<int>& nums, int d, vector<vector<int>>& memo){
        if(idx < 0) return 0;
        if(memo[idx][d + 501] != -1) return memo[idx][d + 501];

        int result = 0;
        for(int k = idx - 1; k >= 0; k--){
            if(nums[idx] - nums[k] == d){
                // we need to find for each k every pair and it must be consecutive only
                result = max(result, 1 + solve(k, n, nums, d, memo));
            }
        }

        return memo[idx][d + 501] = result;
    }

public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n; // any array like [1,2] say for example will have the length only as no other element to check with

        int result = 0;
        // d can at max be 500
        // if we want to avoid negative d we are adding a constant 501 to our result everytime
        vector<vector<int>> memo(n, vector<int>(1003, -1));

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                // check all i, j pairs with d difference in the left side of i if we can keep them as part of subsequence
        // can do for each idx and d as well but d can be negative
                int d = nums[j] - nums[i];
                result = max(result, 2 + solve(i, n, nums, d, memo));
            }
        }

        return result;
    }
};