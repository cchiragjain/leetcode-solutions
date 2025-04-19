class Solution {
public:
    int minPairSum(vector<int>& nums) {
        // brute force way will be to generate all pairs
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int maxSum = INT_MIN;
        for(int i = 0; i < n / 2; i++){
            maxSum = max(maxSum, nums[i] + nums[n - i - 1]);
        }

        return maxSum;
    }
};