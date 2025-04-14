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
                        // found another path to reach i
                        // At index 4 (nums[4] = 7), you can reach it from both index 2 and 3 (both give LIS of length 3), so count[4] = count[2] + count[3] = 1 + 1 = 2.
                        count[i] += count[j];
                    } else if(dp[j] + 1 > dp[i]){
                        // found new longest 
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                }
            }
        }

        int result = 0;
        int maxVal = 1;

        for(int num: dp) maxVal = max(maxVal, num);

        for(int i = 0; i < n; i++){
            if(dp[i] == maxVal){
                result += count[i];
            }
        }

        return result;
    }
};