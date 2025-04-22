class Solution {
private:
    int findMin(vector<int>& time){
        int mini = INT_MAX;
        for(int t: time) mini = min(mini, t);
        return mini;
    }

    long long countTrips(vector<int>& time, long long timeTaken){
        long long trips = 0;
        for(int t: time){
            trips += timeTaken / t;
        }
        return trips;
    }

public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long start = 1; // min time unit
        long long end = (long long) findMin(time) * (long long)totalTrips;// if the fastest bus had to take all trips then this much time is required

        while(start <= end){
            long long mid = start + (end - start) / 2;
            cout << countTrips(time, mid) << endl; 
            if(countTrips(time, mid) >= totalTrips){
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        cout << start << " " << end;

        return start;
    }
};