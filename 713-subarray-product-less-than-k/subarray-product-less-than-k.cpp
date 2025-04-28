class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;

        int n = nums.size();
        int count = 0;
        int left = 0;
        int product = 1;

        for(int right = 0; right < n; right++){
            product *= nums[right];

            while(product >= k){
                product = product / nums[left];
                left++;
            }

            count += (right - left + 1);
        }

        return count;
        
        /*
        // brute check all subarrays

        for(int i = 0; i < n; i++){
            int product = 1;
            for(int j = i; j < n; j++){
                product *= nums[j];
                if(product < k){
                    count++;
                } else {
                    break; // no need to go further since nums[i] is positive and product will only increase
                }
            }
        }

        return count;
        */
    }
};