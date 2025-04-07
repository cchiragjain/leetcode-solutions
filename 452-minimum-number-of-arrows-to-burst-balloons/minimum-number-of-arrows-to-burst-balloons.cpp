class Solution {
private:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comp);
        int n = points.size();

        int count = 1;
        int lastShot = points[0][1];

        for(int i = 1; i < n; i++){
            int xStart = points[i][0];
            int xEnd = points[i][1];

            if(xStart <= lastShot && xEnd >= lastShot){
                // this shot will be covered with the previous arrow
                // if say shot at 5 then covers both 2, 5 and 1,6
            } else {
                // new arrow is needed
                count++;
                lastShot = xEnd; // shooting as far right possible in order to cover more axises
            }
        }

        return count;
    }
};