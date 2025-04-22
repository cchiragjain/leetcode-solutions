class Solution {
public:
    int findMax(vector<int>& nums){
        int maxi = INT_MIN;
        for(int num: nums){
            maxi = max(num, maxi);
        }
        return maxi;
    }

    bool notExceedThreshold(vector<int>& nums, int divisor, int threshold){
        int sum = 0;

        for(int num: nums){
            sum += ceil((double) num / (double) divisor );
        }

        if(sum <= threshold){
            return true;
        }

        return false;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1;
        int end = findMax(nums);

        while(start <= end){
            int mid = (end) + (start - end) / 2;
            if(notExceedThreshold(nums, mid, threshold)){
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return start;
    }
};