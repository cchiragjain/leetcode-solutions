class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1);
        vector<int> count(n, 1); // stores count of lis ending at index i

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    // if such length subsequence was already found
                    if(dp[j] + 1 == dp[i]){
                        count[i] += count[j];
                    } else if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                }
            }
        }

        int result = 0;
        int maxVal = INT_MIN;
        for(int num: dp) maxVal = max(maxVal, num);

        for(int i = 0; i < n; i++){
            if(dp[i] == maxVal){
                result += count[i];
            }
        }

        return result;
    }
};