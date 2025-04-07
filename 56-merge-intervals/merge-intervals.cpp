class Solution {
// private:
//     static bool comp(vector<int>& a, vector<int>& b){
//         return a[1] != b[1] ? a[1] < b[1] : a[0] < b[0];
//     }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // we need to merge the interval which can be done simply by comparing interval end to next interval start and pushing to vector
        // but there exists cases like [[1,3], [2, 6], [6, 10]]
        // now first 2 will merge in one 1, 6 but then 6, 10 can also be merged to return 1,10 which is one final interval 

        // sort with ascending order end times so to have better chances of finding closer start times 
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for(int i = 1; i < n; i++){
            int lastMergedStartTime = merged.back()[0];
            int lastMergedEndTime = merged.back()[1];

            int start = intervals[i][0];
            int end = intervals[i][1];

            if(start > lastMergedEndTime){
                merged.push_back({start,end});
            } else if(end > lastMergedEndTime){
                // if that is not the case need to update the last merged interval end time in order to merge this
                // ex. if [1,3] was there and we are now at [2,6] then can just change 1,3 to 1, 6 to reflect changes

                merged.back()[1] = end;
            }
        }

        return merged;
    }
};