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

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        // return rob(nums, n - 1);
        return robMemo(nums, dp, n - 1);
    }
};