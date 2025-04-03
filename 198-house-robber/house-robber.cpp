class Solution {
private:
    int rob(vector<int>& nums, int i){
        if(i == 0) return nums[0]; // no negative numbers are present since cost 
        // so should always pick this

        if(i < 0) return 0; // out of bounds case may happen say when at house 1 and call pick
        
        // can not pick adjacent elements so if we are picking it cant pick the adjacent
        int pick = nums[i] + rob(nums, i - 2);
        // if not picking consider current house as 0 and pick adjacent
        int notPick = 0 + rob(nums, i - 1);

        return max(pick, notPick);
    }

    int robMemo(vector<int>& nums, vector<int>& dp, int i){
        if(i == 0) return nums[0]; // no negative numbers are present since cost 
        // so should always pick this

        if(i < 0) return 0; // out of bounds case may happen say when at house 1 and call pick
        
        if(dp[i] != -1) return dp[i];

        // can not pick adjacent elements so if we are picking it cant pick the adjacent
        int pick = nums[i] + robMemo(nums, dp, i - 2);
        // if not picking consider current house as 0 and pick adjacent
        int notPick = 0 + robMemo(nums, dp, i - 1);

        return dp[i] = max(pick, notPick);
    }

    int robTab(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n, -1);
        
        int maxAmount = INT_MIN;
        dp[0] = nums[0];
        
        if(n > 1)
            dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++){
            int pick = nums[i] + dp[i - 2];
            int notPick = 0 + dp[i - 1];
            dp[i] = max(pick, notPick);
        }

        for(int num: dp){
            maxAmount = max(num, maxAmount);
        }

        return maxAmount;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        // return rob(nums, n - 1);
        // return robMemo(nums, dp, n - 1);
        return robTab(nums);
    }
};












