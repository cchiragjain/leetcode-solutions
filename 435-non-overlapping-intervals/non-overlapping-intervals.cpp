class Solution {
private:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // similar to activity selection/ n meetings problem
        // in order to find number of intervals to remove so that the rest are non overlapping we can just find max number of non overlapping intervals instead
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), comp);
        
        // these are sorted on the basis of there end time now
        // think of this like meeting times only
        
        int count = 1; // count non overlapping intervals
        int lastIntervalEndTime = intervals[0][1];
        for(int i = 1; i < n; i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(start >= lastIntervalEndTime) {
                count++;
                lastIntervalEndTime = end;
            }
        }

        return n - count;
    }
};