class Solution {
private:
    int findMax(vector<int>& nums){
        int maxi = INT_MIN;
        for(int num: nums) maxi = max(maxi, num);
        return maxi;
    }

    long long calculateTotalHoursTakenUsingThisK(vector<int>& piles, int k){
        long long totalHours = 0;

        for(int pileSize: piles){
            totalHours += pileSize / k;
            if(pileSize % k != 0){
                totalHours++;
            }
        }

        return totalHours;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        // k is bananas/ hour koko can eat
        int minK = 1;
        int maxK = findMax(piles); // this is the max she could eat there is no reason to go more than this

        // since we are searching on increasing space can use binary search
        while(minK <= maxK){
            int mid = minK + (maxK - minK) / 2;

            long long totalHoursUsingThisK = calculateTotalHoursTakenUsingThisK(piles, mid);

            if(totalHoursUsingThisK <= h){
                maxK = mid - 1; // find more min
            } else {
                minK = mid + 1; // need to find bigger range
            }
        }

        return minK;

        /*
        gives tle for large inputs. O(max K * N) time
        for(int i = minK; i <= maxK; i++){
            long long totalHoursUsingThisK = calculateTotalHoursTakenUsingThisK(piles, i);

            if(totalHoursUsingThisK <= h){
                return i;
            }
        }

        return -1;
        */
    }
};