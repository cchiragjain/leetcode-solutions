class Solution {
public:
    // normal interval approach/ acitivty seleciton will not work since need to find overlap with not jsut previous but all previous

    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
    
        // sort on the basis of start time so that logically we assing rooms to those meetings first that want to start first
        sort(intervals.begin(), intervals.end()); 
        priority_queue<int, vector<int>, greater<int>> pq; // stores the earliest finishing meetings. so when we need to assign room to a new meeting check with this if meeting can finish before then can just assign this room

        int roomCount = 1;
        pq.push(intervals[0][1]); // this meeting will start the earliest so it will occupy the first room. other meetings will have to wait for this one to get this room or take a new room
                                   
        for(int i = 1; i < n; i++){
            int startTime = intervals[i][0];
            int endTime = intervals[i][1];

            if(startTime >= pq.top()){
                pq.pop(); // use the same room
            } else {
                roomCount++;
            }
            // in both cases we need to consider the end time for this new meeting
            pq.push(endTime);
        }

        return roomCount;
    }
};