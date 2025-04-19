class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        
        long long result = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            int low = lower - nums[i];
            int high = upper - nums[i];
            
            // Find count of numbers in nums[j] where j > i
            // i+1 to n-1 range using binary search
            int start = lower_bound(nums.begin() + i + 1, nums.end(), low) - nums.begin();
            int end = upper_bound(nums.begin() + i + 1, nums.end(), high) - nums.begin();
            
            result += end - start;
        }
        
        return result;
    }
};