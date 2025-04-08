class Solution {
private:
    bool canJump(vector<int>& nums, int currentStep, int n, vector<int>& memo){
        if(currentStep == n - 1){
            return true;
        } else if(currentStep >= n) {
            return false;
        }
        
        // 0 and 1 can be used as false and true as well
        if(memo[currentStep] != -1) return memo[currentStep];

        int maxJump = nums[currentStep];
        // if standing at 2 then can take a jump of 1 or 2
        // trying both and checking which one reaches first
        for(int i = 1; i <= maxJump; i++){
            if(canJump(nums, currentStep + i, n, memo)) {
                memo[currentStep + i] = 1;
                return true;
            }
        }

        memo[currentStep] = 0;
        // if starting from this not possible then return false
        return memo[currentStep];
    }

    bool canJumpTabulation(vector<int>& nums, int n){
        vector<int> dp(n, -1);
        dp[n - 1] = 1; // if at last index can always reach there ( already there )

        // now check from behind if doing nums[i] jump can reach an index from where we can reach end then using i we can also reach end

        for(int i = n - 2; i >= 0; i--){
            int maxJump = nums[i];
            bool canReach = false;
            for(int j = 1; j <= maxJump; j++){
                int newPosition = i + j; // current + jump size
                if(newPosition < n && dp[newPosition] == 1){
                    dp[i] = 1;
                    canReach = true;
                    break;
                }
            }
            // will only reach here if the loop did not break then was not able to find any position
            if(canReach == false) dp[i] = 0;
        }

        for(int num: dp){
            cout << num << " ";
        }

        return dp[0] == 1;
    }

public:
    bool canJump(vector<int>& nums) {
        int currentStep = 0;
        int n = nums.size();
        // -1 means not solved
        // 0 means cant reach
        // 1 means can reach
        // vector<int> memo(n, -1);

        // return canJump(nums, currentStep, n, memo);
        return canJumpTabulation(nums, n);
    }
};