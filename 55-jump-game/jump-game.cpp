class Solution {
private:
    bool canJump(vector<int>& nums, int currentStep, int n, vector<int>& memo){
        if(currentStep == n - 1){
            return true;
        } else if(currentStep >= n) {
            return false;
        }

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

public:
    bool canJump(vector<int>& nums) {
        int currentStep = 0;
        int n = nums.size();
        vector<int> memo(n, -1);

        return canJump(nums, currentStep, n, memo);
    }
};