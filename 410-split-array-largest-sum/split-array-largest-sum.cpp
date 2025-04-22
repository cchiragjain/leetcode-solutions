class Solution {
public:
    int findMax(vector<int>& v){
        int maxi = INT_MIN;
        for(int num: v){
            maxi = max(num, maxi);
        }
        return maxi;
    }

    int findSum(vector<int>& nums){
        int sum = 0;
        for(int num: nums){
            sum += num;
        }
        return sum;
    }

    bool canSplitInKSubarrays(vector<int>& v, int maxSum, int maxSubarray){
        int subArrayCount = 1;
        int sum = v[0];

        for(int i = 1; i < v.size(); i++){
            if(sum + v[i] > maxSum){
                subArrayCount++;
                sum = v[i];
            } else{
                sum += v[i];
            }
        }

        if(subArrayCount > maxSubarray){
            return false;
        } else{
            return true;
        }
    }

    int splitArray(vector<int>& nums, int k) {
        int start = findMax(nums);
        int end = findSum(nums);

        while(start <= end){
            int mid = end + (start - end) / 2;
            if(canSplitInKSubarrays(nums, mid, k)){
                end = mid - 1;
            } else{
                start = mid + 1;
            }
        }

        return start;
    }
};