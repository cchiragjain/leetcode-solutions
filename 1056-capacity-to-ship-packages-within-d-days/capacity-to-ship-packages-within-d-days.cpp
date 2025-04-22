class Solution {
public:
    int findMax(vector<int>& nums){
        int maxi = INT_MIN;
        for(int num: nums){
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

    int calculateDaysForGivenCapacity(vector<int>& nums, int capacity){
        int days = 1;
        int load = 0;

        for(int num: nums){
            if((num + load) > capacity){
                // shift to new day and pass the load to that day
                days++;
                load = num;
            } else{
                load += num; // add load to the same day
            }
        }

        return days;
    }

    int shipWithinDays(vector<int>& nums, int days) {
        int start = findMax(nums);
        int end = findSum(nums);

        while(start <= end){
            int mid = (end) + (start - end) / 2;
            int daysForCapacity = calculateDaysForGivenCapacity(nums, mid);

            if(daysForCapacity <= days){
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return start;
    }
};