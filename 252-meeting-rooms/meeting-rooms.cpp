class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }

    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 0) return true;

        sort(intervals.begin(), intervals.end(), cmp);
        int lastCompletedMeetingTime = intervals[0][1];

        for(int i = 1; i < n; i++){
            if(!(intervals[i][0] >= lastCompletedMeetingTime)) {
                return false;
            }
            lastCompletedMeetingTime = intervals[i][1]; 
        }

        return true;
    }
};