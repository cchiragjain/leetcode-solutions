class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums[0] == target){
            return 0;
        }

        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int result = -1;
        
        while(start <= end){
            int mid = end + (start - end) / 2;

            if(nums[mid] == target){
                return mid;
            } 
            // sorted in left
            // ex. array will be [4, 5, 6, 7, 0, 1, 2]
            else if(nums[start] <= nums[mid]){
                // target can lie in this range
                if(nums[start] <= target && target < nums[mid]){
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } 
            // sorted in right direction
            else if(nums[start] >= nums[mid]){
                if(nums[mid] < target && target <= nums[end]){
                    start = mid + 1;
                } else{
                    end = mid - 1;
                }
            }
        }

        return result;
    }
};